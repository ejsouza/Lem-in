/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:48:57 by esouza            #+#    #+#             */
/*   Updated: 2017/12/04 17:07:26 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int						i;
	unsigned char			ch;
	unsigned char			*dst_cpy;
	unsigned char			*src_cpy;

	i = 0;
	ch = (unsigned char)c;
	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	while (n > 0 && src_cpy[i] != ch)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
		n--;
	}
	if (n > 0 && src_cpy[i] == ch)
	{
		dst_cpy[i] = src_cpy[i];
		return (&dst_cpy[i + 1]);
	}
	return (NULL);
}
