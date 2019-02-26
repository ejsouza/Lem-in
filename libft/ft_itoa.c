/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:09:17 by esouza            #+#    #+#             */
/*   Updated: 2017/12/04 15:42:31 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_calculatesize(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i += 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*array;
	size_t		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_calculatesize(n);
	if (!(array = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		array[0] = '0';
	if (n < 0)
	{
		array[0] = '-';
		n *= -1;
	}
	array[len] = '\0';
	while (n)
	{
		len--;
		array[len] = (n % 10) + '0';
		n /= 10;
	}
	return (array);
}
