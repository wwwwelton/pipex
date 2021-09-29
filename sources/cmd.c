/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 02:20:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		else if (execve(cmd[0], cmd, pipex->envp) != -1)
			execute_perror(cmd, cmd[0], 126, pipex);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
}

int	execute_commands(t_pipex *pipex)
{
	int		i;
	char	**cmd;

	i = 0;
	while (i < (pipex->argc - 3))
	{
		cmd = cmd_split(pipex->argv[i + 2], pipex);
		if (access(cmd[0], F_OK) == 0)
			execute_command(pipex->pip[i], cmd, pipex);
		else
			execute_perror(cmd, cmd[0], 127, pipex);
		free_splited_mat(cmd);
		i++;
	}
	return (0);
}
