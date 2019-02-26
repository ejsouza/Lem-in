/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_adjusted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:18:22 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:48:22 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		right_padd(t_ptf *p, t_verify **v)
{
	int		len;
	int		i;
	char	*tmp;
	char	ch;

	i = 0;
	ch = ' ';
	len = (*p).x;
	if (!(tmp = (char *)malloc(len + 1)))
		return (1);
	tmp[len] = '\0';
	tmp = ft_memmove(tmp, (*v)->target, len);
	if ((*p).type == '%' && (*v)->zero)
		ch = '0';
	while ((*v)->widthnum > len++)
		(*v)->target[i++] = ch;
	len = 0;
	while (len < (*p).x)
		(*v)->target[i++] = tmp[len++];
	(*p).x = i;
	(*v)->target[(*p).x] = '\0';
	free(tmp);
	return (0);
}

static char		foo(t_ptf *p, t_verify **v)
{
	if ((*v)->dot == 1 && (*v)->zero == 1 && ((*p).type == 'x' ||
		(*p).type == 'i' || (*p).type == 'd' || (*p).type == 'X' ||
		(*p).type == 'o' || (*p).type == 'u' || (*p).type == 'O'))
	{
		return (' ');
	}
	return ('0');
}

static int		zero_padd(t_ptf *p, t_verify **v)
{
	int		i;
	int		k;
	char	ch;
	char	*tmp;

	if ((*v)->zero == 1)
	{
		i = 0;
		k = 0;
		ch = foo(p, v);
		(*p).len = (*p).x;
		if (!(tmp = (char *)malloc((*p).x + 1)))
			return (1);
		tmp[(*p).x] = '\0';
		(*v)->pwidth = ((*v)->pwidth < 0) ? 0 : (*v)->pwidth;
		tmp = ft_memmove(tmp, (*v)->target, (*p).x);
		while (((*v)->widthnum - (*v)->pwidth) > (*p).x++)
			(*v)->target[i++] = ch;
		while (k < (*p).len)
			(*v)->target[i++] = tmp[k++];
		(*p).x = i;
		(*v)->target[(*p).x] = '\0';
		free(tmp);
	}
	return (0);
}

void			ft_precision_fmt(t_ptf *p, t_verify **v)
{
	ft_pre_precision(p, v);
	zero_padd(p, v);
	right_padd(p, v);
	ft_add_sign(p, v);
}

int				ft_right_adjusted(t_ptf *p, t_verify **v)
{
	ft_precision_fmt(p, v);
	ft_hash(p, v);
	if ((*p).nb < 0)
	{
		(*p).totalbytes = -1;
		return (-1);
	}
	(*p).totalbytes += write(1, (*p).buff, (*p).j);
	(*p).totalbytes += write(1, (*v)->target, (*p).x);
	return (0);
}
