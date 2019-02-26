/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:08:24 by esouza            #+#    #+#             */
/*   Updated: 2017/12/04 23:29:30 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	unsigned	i;
	char		*array;

	if (s)
	{
		i = 0;
		array = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (!array)
			return (NULL);
		while (s[i] != '\0')
		{
			array[i] = f((char)s[i]);
			i++;
		}
		array[i] = '\0';
		return (array);
	}
	return (NULL);
}
