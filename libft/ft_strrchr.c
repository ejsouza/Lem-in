/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:16:52 by esouza            #+#    #+#             */
/*   Updated: 2017/11/21 09:59:49 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int				i;
	int				flag;
	unsigned char	ch;

	i = 0;
	flag = -1;
	ch = (unsigned char)c;
	if (ch == '\0')
		return ((char *)&s[ft_strlen((char *)s)]);
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			flag = i;
		i++;
	}
	if (flag >= 0)
		return ((char *)&s[flag]);
	return (0);
}
