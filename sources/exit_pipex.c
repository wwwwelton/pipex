/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:11:39 by wleite            #+#    #+#             */
/*   Updated: 2021/09/28 00:49:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	free_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->pip)
	{
		while (pipex->pip[++i])
			ft_free_ptr((void *)&pipex->pip[i]);
		ft_free_ptr((void *)&pipex->pip);
	}
	return (0);
}

int	exit_pipex(t_pipex *pipex)
{
	close(pipex->file_in);
	close(pipex->file_out);
	free_pipes(pipex);
	return (0);
}
