/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:39:56 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 18:26:10 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_here_doc(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->here_doc = 1;
	pipex->limiter = argv[2];
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->cmd_count = argc - 4;
	pipex->offset = 3;
	pipex->state_lock = 0;
	create_pipes(pipex);
	open_files(pipex);
	create_pipeline(pipex);
	return (0);
}
