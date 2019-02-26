/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_t_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:12:56 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:33:17 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_reverse_result(char *ar)
{
	char	tmp[42];
	short	i;
	short	k;

	i = ft_strlen(ar) - 1;
	ft_bzero(tmp, 42);
	k = 0;
	while (i >= 0)
		tmp[k++] = ar[i--];
	i = 0;
	while ((ar[i] = tmp[i]))
		i++;
	return (ar);
}

char			*ft_intmax_t_itoa(intmax_t n, char *base)
{
	char	*array;
	short	index;
	short	int_len;
	short	base_len;

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
