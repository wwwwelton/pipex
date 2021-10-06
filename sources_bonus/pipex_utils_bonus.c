/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/10/06 09:39:09 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup42(int fd1, int fd2, char **cmd, t_pipex *pipex)
{
	if (dup2(fd1, fd2) == -1)
		execute_perror(cmd, "execute_command", 1, pipex);
}

void	mat_replace_all(char **cmds, char *old_word, char *new_word)
{
	int	i;

	i = -1;
	while (cmds[++i])
		str_replace_all(&cmds[i], old_word, new_word);
}

void	str_replace_all(char **str, char *old_word, char *new_word)
{
	if (!str || !*str)
		return ;
	while (ft_strnstr(*str, old_word, ft_strlen(*str)))
		*str = ft_str_replace(*str, old_word, new_word);
}
