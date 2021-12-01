/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/12/01 19:40:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc > 5)
	{
		ft_putstr_fd("Error\nToo many arguments!\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc == 5)
	{
		init_pipex(argc, argv, envp, &pipex);
		execute_commands(&pipex);
		exit_pipex(&pipex);
	}
	else
	{
		ft_putstr_fd("Error\nToo few arguments!\n", 2);
		exit(EXIT_FAILURE);
	}
	return (pipex.state_lock);
}
