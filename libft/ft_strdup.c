/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:56:34 by esouza            #+#    #+#             */
/*   Updated: 2017/12/02 16:05:36 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*array;

	array = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!array)
		return (NULL);
	ft_strcpy(array, s1);
	return (array);
}
