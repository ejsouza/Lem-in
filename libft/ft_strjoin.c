/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:39:12 by esouza            #+#    #+#             */
/*   Updated: 2017/12/03 12:34:31 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_getresult(char const *s1, char const *s2, char *array)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		array[i] = s2[k];
		i++;
		k++;
	}
	array[i] = '\0';
	return (array);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*array;

	if (s1 && s2)
	{
		len = ((ft_strlen((char *)s1)) + (ft_strlen((char *)s2)) + 1);
		if (!(array = (char *)malloc(sizeof(*array) * len)))
			return (NULL);
		return (ft_getresult(s1, s2, array));
	}
	return (NULL);
}
