/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:11:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 23:59:23 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	exit_pipex(t_pipex *pipex)
{
	close_pipes(pipex);
	free_pipes(pipex);
	return (0);
}
