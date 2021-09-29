/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 01:20:51 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_perror(char *error, int code)
{
	perror(error);
	exit(code);
}

void	execute_perror(char **cmd, char *error, int code, t_pipex *pipex)
{
	ft_strlcpy(pipex->error_str, error, ft_strlen(error) + 1);
	free_splited_mat(cmd);
	exit_pipex(pipex);
	exit_perror(pipex->error_str, code);
}
