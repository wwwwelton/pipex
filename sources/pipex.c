/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/09/23 10:12:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_args(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		printf("\n%s argv[%d]", argv[i], i);
		i++;
	}
	i = 0;
	printf("\n");
	while (envp[i])
	{
		if (strncmp("PATH", envp[i], 4) == 0)
		{
			//printf("\n%s envp[%d]", envp[i], i);
			printf("\nPATH found!");
			break ;
		}
		i++;
	}
	printf("\n");
}

// static char	*get_first_word(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i] != ' ')
// 		i++;
// }

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc >= 4)
	{
		char *args[3];

		print_args(argc, argv, envp);

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
