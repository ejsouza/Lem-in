/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chose_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 09:48:15 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:24:58 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chose_itoa(t_ptf *p, t_verify **v)
{
	if (p->type == 'd' || p->type == 'i' || p->type == 'D')
		return (ft_signed_itoa(p->va_intmax, "0123456789", p));
	else if (p->type == 'x')
		return ((ft_unsigned_itoa(p->va_uns_int, "0123456789abcdef", p, v)));
	else if (p->type == 'p')
		return ((ft_unsigned_itoa(p->va_uns_int, "0123456789abcdef", p, v)));
	else if (p->type == 'X')
		return ((ft_unsigned_itoa(p->va_uns_int, "0123456789ABCDEF", p, v)));
	else if (p->type == 'o' || p->type == 'O')
		return (ft_unsigned_itoa(p->va_uns_int, "01234567", p, v));
	else if (p->type == 'u' || p->type == 'U')
		return (ft_unsigned_itoa(p->va_uns_int, "0123456789", p, v));
	else if (p->type == 'c' || p->type == 'C')
		return (ft_char_itoa((*p).va_intmax, p, v));
	else if (p->type == 'S' || (p->type == 's' && (*v)->l > 0))
		return (ft_wchar(p, v));
	else if (p->type == 's')
		return (ft_string(p, v));
	else if (p->type == '%')
	{
		(*p).tmp[0] = '%';
		return (1);
	}
	return (0);
}
