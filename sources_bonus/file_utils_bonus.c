/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:28:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 18:08:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_files(t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->file_out = open(pipex->argv[pipex->argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0777);
	else
		pipex->file_out = open(pipex->argv[pipex->argc - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->file_out < 0)
		exit_perror(pipex->argv[pipex->argc - 1], 0);
	if (!pipex->here_doc)
	{
		pipex->file_in = open(pipex->argv[1], O_RDONLY);
		if (pipex->file_in < 0)
		{
			ft_putstr_fd("0\n", pipex->file_out);
			exit_perror(pipex->argv[1], 0);
		}
	}
	return (0);
}
