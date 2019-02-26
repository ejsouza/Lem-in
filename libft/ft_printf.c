/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:23:28 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:43:03 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_write_to_percent(const char *restrict format, t_ptf *p)
{
	(*p).j = 0;
	(*p).x = 0;
	while (format[p->at] && format[p->at] != '%')
	{
		p->buff[(*p).j++] = format[p->at++];
		if ((*p).j == (BASE - 1))
		{
			p->totalbytes += write(1, p->buff, (*p).j);
			ft_bzero(p->buff, BASE);
			(*p).j = 0;
		}
	}
	(*p).buff[(*p).j] = '\0';
	if (format[p->at] == '\0')
		p->totalbytes += write(1, p->buff, (*p).j);
	else if (format[p->at] != '\0')
	{
		p->at++;
		ft_parsing(format, p);
	}
}

int				ft_printf(const char *restrict format, ...)
{
	static t_ptf		p;

	p.at = 0;
	p.len = 0;
	p.totalbytes = 0;
	va_start(p.ap, format);
	ft_write_to_percent(format, &p);
	va_end(p.ap);
	return (p.totalbytes);
}
