/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/09/28 08:09:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(int *fd, char *cmd, char **cmd_args, char **envp)
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

int	pipex(int argc, char **argv, char **envp)
{
	int		i;
	char	**cmd;
	t_pipex	pipex;

	if (argc >= 5)
	{
		init_pipex(argc, argv, envp, &pipex);

		i = 0;
		while (i < (argc - 2))
		{
			cmd = cmd_split(argv[i + 2], &pipex);
			exec_cmd(pipex.pip[i], cmd[0], cmd, envp);
			free_splited_mat(cmd);
			i++;
		}

		// debug(&pipex);
		exit_pipex(&pipex);
	}
	else
	{
		printf("Error\nToo few arguments!\n");
		exit(1);
	}
	return (0);
}
