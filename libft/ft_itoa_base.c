/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:03:00 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:34:50 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long			ft_calculatesize(long long int n)
{
	int			i;

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

char						*ft_itoa_base(long long n, char *base)
{
	char		*array;
	long long	len;

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
		array[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (array);
}
