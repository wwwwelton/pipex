/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:25:24 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 16:10:58 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	revert_created_pipes(t_pipex *pipex, int size)
{
	int	i;

	i = -1;
	if (pipex->pipe)
	{
		while (pipex->pipe[++i] && i < size)
			ft_free_ptr((void *)&pipex->pipe[i]);
		ft_free_ptr((void *)&pipex->pipe);
	}
	return (0);
}

int	create_pipes(t_pipex *pipex)
{
	int	i;

	pipex->pipe = (int **)malloc(sizeof(int *) * (pipex->cmd_count + 1));
	if (!pipex->pipe)
		return (1);
	i = -1;
	while (++i < (pipex->cmd_count))
	{
		pipex->pipe[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipex->pipe[i] || pipe(pipex->pipe[i]))
		{
			revert_created_pipes(pipex, i);
			perror("create_pipes");
			exit(1);
		}
	}
	pipex->pipe[i] = NULL;
	pipex->pipe_count = i;
	return (0);
}

int	create_pipeline(t_pipex *pipex)
{
	int	i;

	if (pipex->here_doc)
		read_std_input(pipex->pipe[0], pipex->limiter);
	else
		pipex->pipe[0][0] = pipex->file_in;
	i = -1;
	while (++i < (pipex->pipe_count - 1))
		pipex->pipe[i][1] = pipex->pipe[i + 1][1];
	pipex->pipe[pipex->pipe_count - 1][1] = pipex->file_out;
	return (0);
}

int	close_pipes(t_pipex *pipex)
{
	int	i;

	if (!pipex->pipe)
		return (1);
	i = -1;
	while (pipex->pipe[++i])
	{
		close(pipex->pipe[i][0]);
		close(pipex->pipe[i][1]);
	}
	return (0);
}
