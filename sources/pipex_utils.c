/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:38 by wleite            #+#    #+#             */
/*   Updated: 2021/09/28 23:38:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_splited_mat(char **mat)
{
	int	i;

	i = -1;
	if (mat)
	{
		while (mat[++i])
			ft_free_ptr((void *)&mat[i]);
		ft_free_ptr((void *)&mat);
	}
}

void	str_replace_all(char **str, char *old_word, char *new_word)
{
	char	*tmp;

	if (!str || !*str)
		return ;
	while (ft_strnstr(*str, old_word, ft_strlen(*str)))
	{
		tmp = *str;
		*str = ft_str_replace((const char *)*str, old_word, new_word);
		ft_free_ptr((void *)&tmp);
	}
}

void	mat_replace_all(char **cmds, char *old_word, char *new_word)
{
	int	i;

	i = -1;
	while (cmds[++i])
		str_replace_all(&cmds[i], old_word, new_word);
}
