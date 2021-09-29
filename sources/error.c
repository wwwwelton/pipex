/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 03:44:49 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_perror(char *error, int code)
{
	perror(error);
	exit(code);
}

void	command_not_found(char *cmd, char **cmd_splitted, t_pipex *pipex)
{
	ft_strlcpy(pipex->error_str, cmd, ft_strlen(cmd) + 1);
	if (cmd_splitted)
		free_splited_mat(cmd_splitted);
	exit_pipex(pipex);
	ft_putstr_fd("command not found", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(pipex->error_str, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

void	execute_perror(char **cmd, char *error, int code, t_pipex *pipex)
{
	ft_strlcpy(pipex->error_str, error, ft_strlen(error) + 1);
	free_splited_mat(cmd);
	exit_pipex(pipex);
	exit_perror(pipex->error_str, code);
}
