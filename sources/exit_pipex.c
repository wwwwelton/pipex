/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:11:39 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 02:10:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	close_pipes(t_pipex *pipex)
{
	int	i;

	if (!pipex->pip)
		return (1);
	i = -1;
	while (pipex->pip[++i])
	{
		close(pipex->pip[i][0]);
		close(pipex->pip[i][1]);
	}
	return (0);
}

static int	free_pipes(t_pipex *pipex)
{
	int	i;

	if (!pipex->pip)
		return (1);
	i = -1;
	while (pipex->pip[++i])
		ft_free_ptr((void *)&pipex->pip[i]);
	ft_free_ptr((void *)&pipex->pip);
	return (0);
}

int	exit_pipex(t_pipex *pipex)
{
	close_pipes(pipex);
	free_pipes(pipex);
	return (0);
}
