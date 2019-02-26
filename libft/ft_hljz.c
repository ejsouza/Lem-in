/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hljz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:30:05 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:30:36 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_hljz(const char *restrict format, t_ptf *p, t_verify **v)
{
	while ((format[(*p).at] == 'h' || format[(*p).at] == 'l' ||
				format[(*p).at] == 'j' || format[(*p).at] == 'z'))
	{
		if (format[(*p).at] == 'h')
			(*v)->h++;
		else if (format[(*p).at] == 'l')
			(*v)->l++;
		else if (format[(*p).at] == 'j')
			(*v)->j++;
		else if (format[(*p).at] == 'z')
			(*v)->z++;
		(*p).at++;
	}
	return (((*v)->h <= 2) && ((*v)->l <= 2) && ((*v)->j <= 1) &&
			((*v)->z <= 1));
}

char		ft_def_ch(t_ptf *p, t_verify **v)
{
	char ch;

	if (!((*p).x == 1 && (*p).type == '%'))
		ch = 0;
	if (((*v)->plus || (*v)->space) && ((*p).type != 'u' && (*p).type != 'c'))
		ch = ((*v)->plus == 1) ? '+' : ' ';
	if ((*p).va_int < 0 || (*p).va_intmax < 0)
		ch = '-';
	if (((*p).x == 1 && (*p).type == '%'))
		ch = 0;
	return (ch);
}

void		ft_handler(t_ptf *p, t_verify **v)
{
	(*p).x++;
	if ((*v)->plus == 1)
		(*v)->target[0] = '+';
	else if ((*v)->space == 1)
		(*v)->target[0] = ' ';
}

int			ft_verify_type(const char *restrict format, t_ptf *p)
{
	int		i;
	char	*tab;

	i = 0;
	(*p).flag = 0;
	tab = "sSpdDioOuUxXcC%";
	while (tab[i])
	{
		if (format[(*p).at] == tab[i])
		{
			(*p).type = format[(*p).at];
			(*p).flag = 1;
			(*p).at++;
			return (1);
		}
		i++;
	}
	return (0);
}
