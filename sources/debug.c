/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:50:37 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 16:12:25 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	debug(t_pipex *pipex)
{
	int	i;

	printf("\ncmd_count: %d", pipex->cmd_count);
	printf("\npipe_count: %d", pipex->pipe_count);
	printf("\nlast_pipe: %p\n", pipex->pipe[pipex->pipe_count]);
	printf("argc_size: %d\n", pipex->offset);
	printf("argc_size: %d\n", pipex->argc);
	i = 0;
	while (i < pipex->argc)
	{
		printf("\n%s argv[%d]", pipex->argv[i], i);
		i++;
	}
	i = 0;
	printf("\n");
	while (pipex->envp[i])
	{
		if (strncmp("PATH=", pipex->envp[i], 4) == 0)
		{
			printf("\nPATH found!");
			break ;
		}
		i++;
	}
	printf("\n");
}
