/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:11:39 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 00:40:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pfree_pipes(t_pipex *pipex, int size)
{
	int	i;

	i = -1;
	if (pipex->pip)
	{
		while (pipex->pip[++i] && i < size)
			ft_free_ptr((void *)&pipex->pip[i]);
		ft_free_ptr((void *)&pipex->pip);
	}
	return (0);
}

static int	create_pipes(t_pipex *pipex)
{
	int	i;

	pipex->pip = (int **)malloc(sizeof(int *) * (pipex->argc - 1));
	if (!pipex->pip)
		return (1);
	i = 0;
	while (i < (pipex->argc - 2))
	{
		pipex->pip[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipex->pip[i] || pipe(pipex->pip[i]))
		{
			pfree_pipes(pipex, i);
			perror("create_pipes");
			exit(1);
		}
		i++;
	}
	pipex->pip[i] = NULL;
	pipex->pip_count = i - 1;
	return (0);
}

static int	create_pipeline(t_pipex *pipex)
{
	int	i;

	pipex->pip[0][0] = pipex->file_in;
	i = -1;
	while (++i < (pipex->pip_count - 1))
		pipex->pip[i][1] = pipex->pip[i + 1][1];
	pipex->pip[pipex->pip_count - 1][1] = pipex->file_out;
	return (0);
}

static int	open_files(t_pipex *pipex)
{
	pipex->file_in = open(pipex->argv[1], O_RDONLY);
	if (pipex->file_in < 0)
		exit_perror("ERROR (input file)", 1);
	pipex->file_out = open(pipex->argv[pipex->argc - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->file_out < 0)
		exit_perror("ERROR (output file)", 1);
	return (0);
}

int	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->cmd_count = argc - 3;
	open_files(pipex);
	create_pipes(pipex);
	create_pipeline(pipex);
	return (0);
}
