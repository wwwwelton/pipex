/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 23:59:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	execute_command(int *fd, char **cmd, t_pipex *pipex)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		execute_perror(cmd, "execute_command", 1, pipex);
	else if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
			execute_perror(cmd, "execute_command", 1, pipex);
		else if (execve(cmd[0], cmd, pipex->envp) == -1)
			execute_perror(cmd, cmd[0], 126, pipex);
	}
	waitpid(-1, &pipex->state_lock, WNOHANG);
	close(fd[0]);
	close(fd[1]);
}

int	execute_commands(t_pipex *pipex)
{
	int		i;
	char	**cmd;

	i = -1;
	while (++i < pipex->cmd_count)
	{
		cmd = cmd_split(pipex->argv[i + pipex->offset], pipex);
		if (access(cmd[0], X_OK) == 0)
			execute_command(pipex->pipe[i], cmd, pipex);
		else
			command_not_found(cmd[0], cmd, pipex);
		free_splited_mat(cmd);
	}
	return (0);
}
