/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:50:37 by wleite            #+#    #+#             */
/*   Updated: 2021/09/26 07:16:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	debug(int argc, char **argv, char **envp)
{
	int	i;

	printf("\nargc[%d]", argc);
	i = 0;
	while (i < argc)
	{
		printf("\n%s argv[%d]", argv[i], i);
		i++;
	}
	i = 0;
	printf("\n");
	while (envp[i])
	{
		if (strncmp("PATH", envp[i], 4) == 0)
		{
			//printf("\n%s envp[%d]", envp[i], i);
			printf("\nPATH found!");
			break ;
		}
		i++;
	}
	printf("\n");
}
