/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_adjusted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:47:32 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:20:09 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_add_sign(t_ptf *p, t_verify **v)
{
	int		len;
	char	ch;

	ch = ft_def_ch(p, v);
	if (ch != 0 && (*p).type != '%' && (*p).type != 'c' && (*p).type != 'C')
	{
		len = 0;
		if ((*v)->target[0] == ' ')
		{
			while ((*v)->target[len] == ' ')
				len++;
			(*v)->target[len - 1] = ch;
		}
		else if (((*v)->target[0] >= '1' && (*v)->target[0] <= '9') ||
			((*v)->target[0] == '0' && (*p).x == 1) || ((*p).nb < (*v)->pwidth))
			ft_add_spag(p, v);
		else
			(*v)->target[0] = ch;
	}
}

void		ft_width_second(t_ptf *p, t_verify **v)
{
	while ((*p).x < (*v)->widthnum)
	{
		(*v)->target[(*p).x] = ' ';
		(*p).x++;
	}
	(*v)->target[(*p).x] = '\0';
}

int			ft_pre_precision(t_ptf *p, t_verify **v)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	(*p).len = ft_chose_itoa(p, v);
	if ((*p).va_intmax >= 0 && (*p).va_intmax <= 0x10FFFF)
		(*p).nb = (*p).len;
	ft_void(p);
	if ((*p).type != '%' && ((*p).type != 'S') && !((*p).type == 's' &&
				(*v)->l == 1))
		i = ft_pre_precision_spag(p, v);
	if ((*v)->pwidth == -1 && (*p).va_intmax == 0 && (*p).va_uns_int == 0 &&
		(*p).type != '%' && (*p).wchar == NULL)
	{
		if ((*v)->plus || (*v)->space)
			ft_handler(p, v);
		return (1);
	}
	while ((*p).len > i)
		(*v)->target[i++] = (*p).tmp[k++];
	(*p).x = i;
	(*v)->target[(*p).x] = '\0';
	return (0);
}

int			ft_precision_first(t_ptf *p, t_verify **v)
{
	if ((*p).type != '%')
	{
		if ((*v)->pwidth == 0 && (*p).va_intmax == 0 && (*p).type != 's' &&
				(*p).va_uns_int == 0 && (*p).type != 'c' && (*p).type != 'C' &&
				(*p).type != 'S' && (*v)->widthnum == 0)
		{
			if ((*v)->plus)
				(*p).totalbytes += write(1, "+", 1);
			else if ((*v)->width)
				(*p).totalbytes += write(1, " ", 1);
			else if ((*p).type == 'o' || (*p).type == 'O')
				(*p).totalbytes += write(1, "0", 1);
			return (1);
		}
	}
	ft_pre_precision(p, v);
	ft_width_second(p, v);
	ft_add_sign(p, v);
	return (0);
}

int			ft_left_adjusted(t_ptf *p, t_verify **v)
{
	ft_precision_first(p, v);
	ft_hexa_prefix(p, v);
	ft_oct(p, v);
	if ((*p).nb < 0)
	{
		(*p).totalbytes = -1;
		return (-1);
	}
	(*p).totalbytes += write(1, (*p).buff, (*p).j);
	(*p).totalbytes += write(1, (*v)->target, (*p).x);
	return (0);
}
