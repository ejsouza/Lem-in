/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:46:58 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:11:41 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_reverse_result(char *ar)
{
	char	tmp[42];
	int		i;
	int		k;

	i = ft_strlen(ar) - 1;
	ft_bzero(tmp, 42);
	k = 0;
	while (i >= 0)
	{
		tmp[k] = ar[i];
		k++;
		i--;
	}
	i = 0;
	while ((ar[i] = tmp[i]))
		i++;
	return (ar);
}

char				*ft_signed_long_itoa(long long int n)
{
	char		*array;
	size_t		len;
	long long	tmp;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	len = ft_intlen(n);
	if (!(array = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		array[0] = '0';
	if (n < 0)
	{
		array[0] = '-';
		tmp = n * -1;
	}
	tmp = (n < 0) ? tmp : n;
	array[len] = '\0';
	while (tmp)
	{
		len--;
		array[len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (array);
}

char				*ft_unsigned_itoa_base(unsigned long long int n, char *base)
{
	char		*array;
	int			index;
	int			int_len;
	size_t		base_len;

	int_len = ft_intlen(n);
	base_len = ft_strlen(base);
	index = 0;
	if (!(array = (char *)malloc(sizeof(char) * (int_len + 1))))
		return (NULL);
	ft_bzero(array, int_len);
	if (n == 0)
		array[0] = '0';
	array[int_len] = '\0';
	while (n)
	{
		array[index] = base[n % base_len];
		n /= base_len;
		index++;
	}
	return (ft_reverse_result(array));
}
