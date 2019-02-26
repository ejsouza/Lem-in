/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:31:39 by esouza            #+#    #+#             */
/*   Updated: 2017/12/02 17:36:13 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*array;

	i = 0;
	if (s)
	{
		array = (char *)malloc(sizeof(*array) * (ft_strlen((char *)s) + 1));
		if (!array)
			return (NULL);
		while (s[i] != '\0')
		{
			array[i] = f(i, (char)s[i]);
			i++;
		}
		array[i] = '\0';
		return (array);
	}
	return (NULL);
}
