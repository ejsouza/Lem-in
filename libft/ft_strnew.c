/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:32:44 by esouza            #+#    #+#             */
/*   Updated: 2017/11/30 23:08:35 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*array;

	array = (char *)malloc(sizeof(*array) * (size + 1));
	if (!array)
		return (NULL);
	ft_memset(array, 0, size);
	array[size] = '\0';
	return (array);
}
