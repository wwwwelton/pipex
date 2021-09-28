/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:40 by wleite            #+#    #+#             */
/*   Updated: 2021/09/27 22:02:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 #include <sys/wait.h>
# include <unistd.h>
# include "../libraries/libft/libft.h"

typedef struct pipex
{
	int	**pip;
	int	file_in;
	int	file_out;
	int	pip_count;
	int	cmd_count;
	int argc;
	char **argv;
	char **envp;
}	t_pipex;


void	debug(t_pipex *pipex);
int		pipex(int argc, char **argv, char **envp);
int		init_pipex(int argc, char **argv, char **envp, t_pipex *pipex);

#endif
