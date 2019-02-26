/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:44:29 by esouza            #+#    #+#             */
/*   Updated: 2017/11/18 12:52:42 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	int			i;
	const char	*s_cpy;
	char		ch;

	i = 0;
	s_cpy = s;
	ch = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (n)
	{
		if (s_cpy[i] == ch)
			return ((char*)&s_cpy[i]);
		i++;
		n--;
	}
	return (NULL);
}
