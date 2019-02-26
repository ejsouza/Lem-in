/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:15:29 by esouza            #+#    #+#             */
/*   Updated: 2018/07/07 21:33:15 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	 The incrementing (*p).at++ at the end of the function ft_flag();
**	causes the need of decrementing by one in the functions
**	ft_get_width(); and ft_precision(); because after calling one of those two
**	functions the function returns to the same point in theft_flags();
**	so it will passthrough the increment at the end of the function.
*/

void		ft_get_width(const char *restrict format, t_ptf *p, t_verify **v)
{
	(*v)->width = 1;
	(*v)->widthnum = ft_atoi(&format[(*p).at]);
	(*p).at += ft_intlen((*v)->widthnum) - 1;
}

void		ft_precision(const char *restrict format, t_ptf *p, t_verify **v)
{
	(*v)->dot = 1;
	(*p).at++;
	if (format[(*p).at] >= '0' && format[(*p).at] <= '9')
	{
		(*v)->pwidth = ft_atoi(&format[(*p).at]);
		(*p).at += ft_intlen((*v)->pwidth) - 1;
		if ((*v)->pwidth == 0)
			(*v)->pwidth = -1;
	}
	else
	{
		(*p).at--;
		(*v)->pwidth = -1;
	}
}

void		ft_initialize_verify(t_verify **v, t_ptf *p)
{
	(*v)->dot = 0;
	(*v)->minus = 0;
	(*v)->plus = 0;
	(*v)->space = 0;
	(*v)->hash = 0;
	(*v)->zero = 0;
	(*v)->width = 0;
	(*v)->widthnum = 0;
	(*v)->pwidth = 0;
	(*v)->h = 0;
	(*v)->l = 0;
	(*v)->j = 0;
	(*v)->z = 0;
	(*p).type = 0;
	(*p).k = 0;
	(*p).x = 0;
	(*p).wchar = NULL;
	(*p).ptrlen = 0;
}

void		ft_flags(const char *restrict format, t_ptf *p, t_verify **v)
{
	while (!(ft_isalpha(format[(*p).at])))
	{
		if (format[(*p).at] == '-')
			(*v)->minus = 1;
		else if (format[(*p).at] == '+')
			(*v)->plus = 1;
		else if (format[(*p).at] == '#')
			(*v)->hash = 1;
		else if (format[(*p).at] == ' ')
			(*v)->space = 1;
		else if (format[(*p).at] == '0')
			(*v)->zero = 1;
		else if (format[(*p).at] >= '1' && format[(*p).at] <= '9')
			ft_get_width(format, p, v);
		else if (format[(*p).at] == '.')
			ft_precision(format, p, v);
		else
			break ;
		(*p).at++;
	}
}

int			ft_parsing(const char *restrict format, t_ptf *p)
{
	t_verify		*v;

	if (!(v = (t_verify *)malloc(sizeof(t_verify))))
		return (-1);
	ft_initialize_verify(&v, p);
	ft_flags(format, p, &v);
	ft_verify_type(format, p);
	if (!p->type)
		ft_no_frmt(format, p, &v);
	else if (p->type)
		ft_parsing_spag(p, &v);
	if (format[(*p).at] != '\0' && (*p).at > 1)
	{
		if ((*p).type == 'C' && (*p).nb < 0)
		{
			free(v);
			(*p).totalbytes = -1;
			return (0);
		}
		ft_write_to_percent(format, p);
	}
	free(v);
	return (0);
}
