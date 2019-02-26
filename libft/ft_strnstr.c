/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:15:48 by esouza            #+#    #+#             */
/*   Updated: 2017/12/02 10:35:56 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			k;
	size_t			k2;

	k = 0;
	if (needle[k] == '\0')
		return ((char*)haystack);
	while (len && haystack[k])
	{
		k2 = k;
		i = 0;
		while (haystack[k2] == needle[i] && i < len)
		{
			if (haystack[k2] == needle[i] && len && needle[i + 1] == '\0')
				return ((char *)&haystack[k]);
			k2++;
			i++;
			if (haystack[k2] == needle[i] && len && needle[i + 1] == '\0')
				return ((char *)&haystack[k]);
		}
		k++;
		len--;
	}
	return (NULL);
}
