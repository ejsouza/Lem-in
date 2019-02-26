/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:03:05 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:32:11 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_int(t_ptf *p, t_verify **v)
{
	if ((*p).type == 'D')
	{
		(*p).va_intmax = va_arg((*p).ap, long int);
	}
	else
	{
		if (!(*v)->h && !(*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_intmax = va_arg((*p).ap, int);
		else if (((*v)->h == 1) && (!(*v)->l) && !(*v)->j && !(*v)->z)
			(*p).va_intmax = (short)va_arg((*p).ap, int);
		else if (((*v)->h == 2) && (!(*v)->l) && !(*v)->j && !(*v)->z)
			(*p).va_intmax = (signed char)va_arg((*p).ap, int);
		else if (!(*v)->h && !(*v)->l && ((*v)->j == 1) && !(*v)->z)
			(*p).va_intmax = va_arg((*p).ap, intmax_t);
		else if (!(*v)->h && ((*v)->l > 0) && !(*v)->j && !(*v)->z)
			(*p).va_intmax = va_arg((*p).ap, long long);
		else if (!(*v)->h && !(*v)->l && !(*v)->j && ((*v)->z == 1))
			(*p).va_intmax = va_arg((*p).ap, ssize_t);
	}
}

void		ft_hexadecimal(t_ptf *p, t_verify **v)
{
	if ((*p).type == 'p')
		(*p).va_uns_int = va_arg((*p).ap, unsigned long int);
	else if ((*p).type == 'O' && !(*v)->l && !(*v)->j && !(*v)->z)
		(*p).va_uns_int = va_arg((*p).ap, unsigned long long int);
	else
	{
		if (!(*v)->h && !(*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, unsigned int);
		else if (!(*v)->h && ((*v)->l == 1) && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, unsigned long int);
		else if (!(*v)->h && ((*v)->j == 1) && !(*v)->l && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, unsigned long int);
		else if (!(*v)->h && ((*v)->l == 2) && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, unsigned long long);
		else if (((*v)->h == 2) && !(*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = (unsigned char)va_arg((*p).ap, unsigned int);
		else if (((*v)->h == 1) && !(*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = (unsigned short)va_arg((*p).ap, unsigned int);
		else if (!(*v)->h && !(*v)->l && !(*v)->j && ((*v)->z > 0))
			(*p).va_uns_int = va_arg((*p).ap, size_t);
	}
}

void		ft_unsigned_int(t_ptf *p, t_verify **v)
{
	if ((*p).type == 'u')
	{
		if (!(*v)->h && !(*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, unsigned int);
		else if (((*v)->h > 0) && !(*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, unsigned int);
		else if (!(*v)->h && ((*v)->l > 0) && !(*v)->j && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, unsigned long long int);
		else if (!(*v)->h && !(*v)->l && ((*v)->j == 1) && !(*v)->z)
			(*p).va_uns_int = va_arg((*p).ap, intmax_t);
		else if (!(*v)->h && !(*v)->l && !(*v)->j && ((*v)->z > 0))
			(*p).va_uns_int = va_arg((*p).ap, size_t);
	}
	else
	{
		(*p).va_uns_int = va_arg((*p).ap, unsigned long);
	}
}

void		ft_char(t_ptf *p, t_verify **v)
{
	if ((*p).type == 'C')
		(*p).va_intmax = va_arg((*p).ap, wint_t);
	else
	{
		if (!(*v)->h && !(*v)->l && !(*v)->j && !(*v)->z)
		{
			(*p).va_intmax = (char)va_arg((*p).ap, int);
		}
		else if (!(*v)->h && (*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_intmax = va_arg((*p).ap, wint_t);
	}
}

void		ft_ptr(t_ptf *p, t_verify **v)
{
	if ((*p).type == 'S')
		(*p).wchar = va_arg((*p).ap, wchar_t *);
	else if ((*p).type == 's' && (*v)->l > 0)
		(*p).wchar = va_arg((*p).ap, wchar_t *);
	else
	{
		if (!(*v)->h && !(*v)->l && !(*v)->j && !(*v)->z)
		{
			(*p).va_ptr = (char *)va_arg((*p).ap, char *);
			if ((*p).va_ptr != NULL)
				(*p).ptrlen = ft_strlen((*p).va_ptr);
		}
		else if (!(*v)->h && (*v)->l && !(*v)->j && !(*v)->z)
			(*p).va_ptr = (char *)va_arg((*p).ap, wchar_t *);
	}
}
