/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fire_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:23:10 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 23:59:24 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	free_pipes(t_pipex *pipex)
{
	int	i;

	if (!pipex->pipe)
		return (1);
	i = -1;
	while (pipex->pipe[++i])
		ft_free_ptr((void *)&pipex->pipe[i]);
	ft_free_ptr((void *)&pipex->pipe);
	return (0);
}

void	free_splited_mat(char **mat)
{
	int	i;

	i = -1;
	if (mat)
	{
		while (mat[++i])
			ft_free_ptr((void *)&mat[i]);
		ft_free_ptr((void *)&mat);
	}
}
