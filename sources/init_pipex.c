/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:11:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 22:23:50 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->here_doc = 0;
	pipex->limiter = NULL;
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->cmd_count = argc - 3;
	pipex->offset = 2;
	pipex->state_lock = 0;
	open_files(pipex);
	create_pipes(pipex);
	create_pipeline(pipex);
	return (0);
}
