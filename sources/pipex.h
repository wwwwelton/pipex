/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:40 by wleite            #+#    #+#             */
/*   Updated: 2021/09/25 19:13:12 by wleite           ###   ########.fr       */
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

void	debug(int argc, char **argv, char **envp);
int		pipex(int argc, char **argv, char **envp);

#endif
