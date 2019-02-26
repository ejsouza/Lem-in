/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:49:35 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:26:28 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_foo(t_ptf *p, t_verify **v, int *x, int *k)
{
	if ((*p).va_int < 0)
	{
		*k = ((*v)->zero == 1) ? 1 : 0;
		*x = ((*v)->zero == 1) ? 1 : 0;
		(*v)->target[0] = '-';
		if (!(*v)->zero && !(*v)->minus)
			(*v)->widthnum--;
	}
	if ((*v)->plus && (!(*v)->minus && (*p).va_int >= 0))
	{
		*x = 1;
		(*v)->target[0] = '+';
	}
	else if ((*v)->space && !(*v)->plus && (*p).va_int >= 0)
	{
		*x = 1;
		(*v)->target[0] = ' ';
	}
}

void		ft_padd_zero(t_ptf *p, t_verify **v)
{
	int		x;
	int		k;

	ft_bzero((*v)->target, 256);
	x = 0;
	k = 0;
	if ((((*p).va_int < 0) || (*v)->plus) || !(*v)->zero)
		ft_foo(p, v, &x, &k);
	ft_signed_itoa((*p).va_int, "0123456789", p);
	if ((*v)->widthnum > ft_intlen((*p).va_int))
	{
		(*v)->widthnum -= ft_intlen((*p).va_int);
		(*v)->widthnum += ((*p).va_int < 0) ? 1 : 0;
		while (x < (*v)->widthnum)
			(*v)->target[x++] = ((*v)->zero) ? '0' : ' ';
		while (((*v)->target[x++] = (*p).tmp[k++]))
			;
	}
	else
		while (((*v)->target[x++] = (*p).tmp[k++]))
			;
	(*p).totalbytes += write(1, (*v)->target, ft_strlen((*v)->target));
	(*p).control--;
}

void		ft_right_padd(t_ptf *p, t_verify **v)
{
	int		x;
	int		k;

	ft_bzero((*v)->target, 256);
	x = 0;
	k = 0;
	if (((*p).va_int < 0) || (*v)->minus || !(*v)->zero)
		ft_foo(p, v, &x, &k);
	ft_signed_itoa((*p).va_int, "0123456789", p);
	if ((*v)->widthnum > ft_intlen((*p).va_int))
	{
		while (((*v)->target[x] = (*p).tmp[k++]))
			x++;
		while (x < (*v)->widthnum)
			(*v)->target[x++] = ' ';
	}
	else
		while (((*v)->target[x++] = (*p).tmp[k++]))
			;
	(*p).totalbytes += write(1, (*v)->target, ft_strlen((*v)->target));
	(*p).control--;
}
