/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/09/23 21:50:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc >= 4)
	{
		char *args[3];

		debug(argc, argv, envp);

		args[0] = "/usr/bin/ls";
		args[1] = "-l";
		args[2] = NULL;

		if (pipe(fd) == -1)
			return (1);

		pid1 = fork();
		if (pid1 < 0)
			return (2);
		if (pid1 == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execve(args[0], args, NULL);
		}

		pid2 = fork();
		if (pid2 < 0)
			return (3);
		if (pid2 == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			execve(args[0], args, NULL);
		}

		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		printf("Too few arguments!\n");
	return (0);
}
