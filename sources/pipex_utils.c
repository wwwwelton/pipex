/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:11:39 by wleite            #+#    #+#             */
/*   Updated: 2021/09/26 09:59:09 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	init_pipes(t_pipex *pipex)
{
	int	i;

	pipex->pip = (int **)malloc(sizeof(int *) * (pipex->argc - 2));
	i = 0;
	while (i < (pipex->argc - 2))
	{
		pipex->pip[i] = (int *)malloc(sizeof(int) * 2);
		pipe(pipex->pip[i]);
		i++;
	}
	pipex->pip[i] = NULL;
	pipex->pip_count = i - 1;
	return (0);
}

static int	conn_pipes(t_pipex *pipex)
{
	int	i;

	pipex->pip[0][0] = pipex->file_in;
	i = 0;
	while (i < (pipex->pip_count - 1))
	{
		pipex->pip[i][1] = pipex->pip[i + 1][1];
		i++;
	}
	pipex->pip[pipex->pip_count - 1][1] = pipex->file_out;
	return (0);
}

int	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->cmd_count = argc - 3;
	pipex->file_in = open(argv[1], O_RDWR);
	pipex->file_out = open(argv[argc - 1], O_RDWR);
	init_pipes(pipex);
	conn_pipes(pipex);
	return (0);
}
