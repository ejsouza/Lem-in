/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:25:15 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:53:32 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short			ft_unsigned_intlen(uintmax_t n)
{
	short	i;

	i = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

static void		ft_reverse(t_ptf *p)
{
	char	ch;
	short	i;
	short	k;

	i = 0;
	k = ft_strlen((*p).tmp) - 1;
	while (i < k)
	{
		ch = (*p).tmp[i];
		(*p).tmp[i] = (*p).tmp[k];
		(*p).tmp[k] = ch;
		i++;
		k--;
	}
}

short			ft_signed_intlen(intmax_t n)
{
	short	i;

	i = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

int				ft_unsigned_itoa(uintmax_t n, char *base, t_ptf *p,
		t_verify **v)
{
	short	nbase;
	short	i;

	nbase = ft_strlen(base);
	i = 0;
	if (n == 0)
	{
		(*p).tmp[0] = '0';
		(*p).tmp[1] = '\0';
		i++;
	}
	while (n)
	{
		(*p).tmp[i] = base[(n % nbase)];
		n /= nbase;
		i++;
	}
	(*p).tmp[i] = '\0';
	ft_reverse(p);
	if (((*p).type == 'x' || (*p).type == 'X') && ((*v)->dot == 1 &&
				(*p).va_uns_int < 1))
		i = 0;
	return (i);
}

int				ft_signed_itoa(intmax_t n, char *base, t_ptf *p)
{
	short	i;
	int		result;
	short	nbase;
	short	foo;

	i = ft_signed_intlen(n);
	result = i;
	nbase = ft_strlen(base);
	(*p).tmp[i] = '\0';
	foo = (n < 0) ? -1 : 1;
	if (n == 0)
	{
		(*p).tmp[0] = '0';
		(*p).tmp[1] = '\0';
	}
	while (n)
	{
		(*p).tmp[i - 1] = ((n % nbase) * foo) + '0';
		n /= nbase;
		i--;
	}
	return (result);
}
