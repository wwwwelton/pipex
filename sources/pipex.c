/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/09/25 19:54:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	int	f_in;
	int	f_out;
	int	fd[2];
	int	pid1;
	int	pid2;
	char **cmd1;
	char **cmd2;
	char *path = "/usr/bin/";

	// (void)argv;
	// (void)envp;
	if (argc >= 5)
	{
		f_in = open("passwd", O_RDWR);
		f_out = open("passwd2", O_RDWR);

		cmd1 = ft_split(argv[2], ' ');
		cmd2 = ft_split(argv[3], ' ');

		pipe(fd);

		dup2(f_in, STDIN_FILENO);
		dup2(f_out, STDOUT_FILENO);

		pid1 = fork();
		if (pid1 == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execve(ft_strjoin(path, cmd1[0]), cmd1, envp);
		}

		pid2 = fork();
		if (pid2 == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			execve(ft_strjoin(path, cmd2[0]), cmd2, envp);
		}
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
	{
		printf("Too few arguments!\n");
		return (1);
	}
	return (0);
}
