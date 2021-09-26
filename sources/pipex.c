/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/09/26 09:53:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(int *fd, char *path, char *cmd, char **cmd_args, char **envp)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(ft_strjoin(path, cmd), cmd_args, envp);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
}

int	pipex(int argc, char **argv, char **envp)
{
	char **cmd1;
	char **cmd2;
	char **cmd3;
	char **cmd4;
	char *path = "/usr/bin/";
	t_pipex pipex;

	if (argc >= 5)
	{
		init_pipex(argc, argv, envp, &pipex);

		cmd1 = ft_split(argv[2], ' ');
		cmd2 = ft_split(argv[3], ' ');
		cmd3 = ft_split(argv[4], ' ');
		cmd4 = ft_split(argv[5], ' ');

		printf("cmd_count: %d", pipex.cmd_count);
		printf("\npip_count: %d", pipex.pip_count);
		printf("\nlast_pip: %p\n", pipex.pip[5]);

		exec_cmd(pipex.pip[0], path, cmd1[0], cmd1, envp);
		exec_cmd(pipex.pip[1], path, cmd2[0], cmd2, envp);
		exec_cmd(pipex.pip[2], path, cmd3[0], cmd3, envp);
		exec_cmd(pipex.pip[3], path, cmd4[0], cmd4, envp);
	}
	else
	{
		printf("Too few arguments!\n");
		return (1);
	}
	return (0);
}
