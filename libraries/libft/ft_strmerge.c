/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:20:56 by wleite            #+#    #+#             */
/*   Updated: 2021/10/12 12:04:42 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmerge(char *s1, char *s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
	{
		ft_free_ptr((void *)&s1);
		ft_free_ptr((void *)&s2);
		return (NULL);
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	ft_free_ptr((void *)&s1);
	ft_free_ptr((void *)&s2);
	return (str);
}
