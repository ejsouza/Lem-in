/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:48:25 by esouza            #+#    #+#             */
/*   Updated: 2017/11/22 09:23:27 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cat(char *dst, const char *src, size_t size)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (dst[i] != '\0')
	{
		i++;
		size--;
	}
	while ((size > 1) && (src[k] != '\0'))
	{
		dst[i] = src[k];
		i++;
		k++;
		size--;
	}
	dst[i] = '\0';
	return (dst);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		total_strs;

	total_strs = ft_strlen(dst) + ft_strlen((char*)src);
	if (size == 0)
	{
		dst = (char *)src;
		return ((unsigned int)ft_strlen((char *)src));
	}
	if (size < ((unsigned int)ft_strlen(dst)))
		return ((ft_strlen((char *)src) + size));
	dst = ft_cat(dst, src, size);
	return (total_strs);
}
