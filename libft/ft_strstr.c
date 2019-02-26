/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:12:12 by esouza            #+#    #+#             */
/*   Updated: 2017/12/02 09:56:52 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			k;
	int			k2;

	k = 0;
	if (needle[k] == '\0')
		return ((char*)haystack);
	while (haystack[k])
	{
		k2 = k;
		i = 0;
		while (haystack[k2] == needle[i])
		{
			if (haystack[k2] == needle[i] && needle[i + 1] == '\0')
				return ((char *)&haystack[k]);
			k2++;
			i++;
			if (haystack[k2] == needle[i] && needle[i + 1] == '\0')
				return ((char *)&haystack[k]);
		}
		k++;
	}
	return (NULL);
}
