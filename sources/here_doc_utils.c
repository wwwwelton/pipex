/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:40:32 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 16:04:57 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_here_doc(char *str)
{
	if (ft_strncmp(str, "here_doc", 9) == 0)
		return (1);
	return (0);
}

void	read_std_input(int *fd, char *limiter)
{
	char	*tmp;

	(void)limiter;
	while (1)
	{
		ft_putstr_fd("here_doc> ", 1);
		tmp = ft_get_next_line(STDIN_FILENO);
		if (ft_strncmp(tmp, limiter, ft_strlen(limiter)) == 0)
		{
			ft_free_ptr((void *)&tmp);
			close(0);
			close(1);
			close(fd[1]);
			tmp = ft_get_next_line(STDIN_FILENO);
			break ;
		}
		ft_putstr_fd(tmp, fd[1]);
		ft_free_ptr((void *)&tmp);
	}
	ft_free_ptr((void *)&tmp);
}
