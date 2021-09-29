/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/28 23:55:47 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_command(int *fd, char *cmd, char **cmd_args, char **envp)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(cmd, cmd_args, envp);
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
	while (i < (pipex->argc - 2))
	{
		cmd = cmd_split(pipex->argv[i + 2], pipex);
		execute_command(pipex->pip[i], cmd[0], cmd, pipex->envp);
		free_splited_mat(cmd);
		i++;
	}
	return (0);
}
