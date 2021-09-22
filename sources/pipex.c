/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/09/22 19:37:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc >= 4)
	{
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
			execlp(argv[2], argv[2], NULL);
		}

		pid2 = fork();
		if (pid2 < 0)
			return (3);
		if (pid2 == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			execlp(argv[3], argv[3], NULL);
		}
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		printf("Too few arguments!\n");
	return (0);
}
