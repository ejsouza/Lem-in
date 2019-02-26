/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:54:15 by esouza            #+#    #+#             */
/*   Updated: 2017/12/05 00:29:14 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*m1;
	unsigned char	*m2;

	i = 0;
	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	if (!m2)
		return (m1[0]);
	if (m1[0] != m2[0] && n > 0)
		return (m1[i] - m2[i]);
	while (n > 0)
	{
		if (m1[i] != m2[i])
			return (m1[i] - m2[i]);
		n--;
		if (m1[i] == '\0' || m2[i] == '\0')
			return (m1[i] - m2[i]);
		if (n == 0)
			return (m1[i] - m2[i]);
		i++;
	}
	return (0);
}
