/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_frmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:59:44 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:37:18 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_spag(const char *restrict format, t_ptf *p, int d, int j)
{
	int	i;
	int	k;

	i = d;
	k = j;
	while (i <= (*p).at)
	{
		if (format[i] == '%' || format[i] == ' ')
			i++;
		if (format[i] == ' ')
			i++;
		if (i <= (*p).at)
			(*p).buff[k++] = format[i++];
	}
	return (k);
}

static int		ft_write_unspecified(const char *restrict format, t_ptf *p)
{
	int		i;
	int		k;

	i = p->at;
	k = 0;
	p->at++;
	if (ft_strlen(format) == 1 && format[0] == '%')
	{
		p->totalbytes = 0;
		(*p).at = 0;
		return (0);
	}
	while (format[i] != '%')
		i--;
	while (p->buff[k])
		k++;
	k = ft_spag(format, p, i, k);
	p->totalbytes += write(1, p->buff, k);
	return (0);
}

static void		ft_left_padd(t_ptf *p, t_verify **v)
{
	int		i;
	char	ch;

	ft_bzero(p->buff, BASE);
	ch = ((*v)->zero == 1) ? '0' : ' ';
	i = 1;
	p->buff[0] = '%';
	while (i < (*v)->widthnum)
	{
		p->buff[i] = ch;
		i++;
	}
	p->totalbytes += write(1, p->buff, i);
}

static void		ft_right_pad(t_ptf *p, t_verify **v)
{
	int		i;
	char	ch;

	ft_bzero(p->buff, BASE);
	ch = ((*v)->zero == 1) ? '0' : ' ';
	i = 0;
	while (i < (*v)->widthnum)
	{
		p->buff[i] = ch;
		i++;
	}
	p->buff[i - 1] = '%';
	p->totalbytes += write(1, p->buff, i);
}

void			ft_no_frmt(const char *restrict format, t_ptf *p, t_verify **v)
{
	if (format[p->at] == '%')
	{
		if ((*v)->minus == 1)
			ft_left_padd(p, v);
		else if (!(*v)->minus && !(*v)->width)
			p->totalbytes += write(1, "%", 1);
		else
			ft_right_pad(p, v);
	}
	else if (!(*v)->minus && format[p->at] != '%' && format[p->at + 1])
		ft_write_unspecified(format, p);
	p->at++;
}
