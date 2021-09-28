/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:50:37 by wleite            #+#    #+#             */
/*   Updated: 2021/09/27 22:37:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	debug(t_pipex *pipex)
{
	int	i;

	printf("\ncmd_count: %d", pipex->cmd_count);
	printf("\npip_count: %d", pipex->pip_count);
	printf("\nlast_pip: %p\n", pipex->pip[6]);
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
		if (strncmp("PATH", pipex->envp[i], 4) == 0)
		{
			//printf("\n%s envp[%d]", envp[i], i);
			printf("\nPATH found!");
			break ;
		}
		i++;
	}
	printf("\n");
}
