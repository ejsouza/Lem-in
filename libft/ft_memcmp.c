/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:56:20 by esouza            #+#    #+#             */
/*   Updated: 2017/11/18 13:12:42 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	i = 0;
	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	while (n)
	{
		if (s1_cpy[i] == s2_cpy[i])
		{
			i++;
			n--;
		}
		else
			return (s1_cpy[i] - s2_cpy[i]);
	}
	return (0);
}
