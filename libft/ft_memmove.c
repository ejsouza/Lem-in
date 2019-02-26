/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:52:59 by esouza            #+#    #+#             */
/*   Updated: 2017/11/30 22:52:47 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dst_cpy;
	unsigned char			*src_cpy;

	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	if (src_cpy < dst_cpy)
	{
		while (len)
		{
			dst_cpy[len - 1] = src_cpy[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst_cpy, src_cpy, len);
	return (dst_cpy);
}
