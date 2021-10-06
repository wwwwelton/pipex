/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/10/06 15:39:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_command(int *fd_tmp, char **cmd, t_pipex *pipex, int index)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		execute_perror(cmd, "execute_command", 1, pipex);
	else if (pid == 0)
	{
		dup42(fd_tmp[0], STDIN_FILENO, cmd, pipex);
		if (index == 1)
			dup42(pipex->file_out, STDOUT_FILENO, cmd, pipex);
		else
			dup42(fd[1], STDOUT_FILENO, cmd, pipex);
		close(fd[0]);
		if (execve(cmd[0], cmd, pipex->envp) == -1)
			execute_perror(cmd, cmd[0], 126, pipex);
	}
	waitpid(-1, &pipex->state_lock, WNOHANG);
	fd_tmp[0] = fd[0];
	close(fd[1]);
}

int	execute_commands(t_pipex *pipex)
{
	int		i;
	int		fd_tmp;
	char	**cmd;

	fd_tmp = pipex->file_in;
	i = -1;
	while (++i < pipex->cmd_count)
	{
		cmd = cmd_split(pipex->argv[i + pipex->offset], pipex);
		if (access(cmd[0], X_OK) == 0)
			execute_command(&fd_tmp, cmd, pipex, i);
		else
			command_not_found(cmd[0], cmd, pipex);
		free_splited_mat(cmd);
	}
	return (0);
}
