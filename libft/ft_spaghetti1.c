/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaghetti1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:30 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:09:47 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_one_byte(t_ptf *p, intmax_t n)
{
	(*p).tmp[0] = n;
	(*p).tmp[1] = '\0';
	return (1);
}

void		ft_add_spag(t_ptf *p, t_verify **v)
{
	int		len;
	char	ch;

	len = ++(*p).x;
	ch = ft_def_ch(p, v);
	if ((*v)->target[(*p).x - 2] == ' ')
		len = --(*p).x;
	while (len)
	{
		(*v)->target[len] = (*v)->target[len - 1];
		len--;
	}
	(*v)->target[0] = ch;
	(*v)->target[(*p).x + 1] = '\0';
}

void		ft_parsing_spag(t_ptf *p, t_verify **v)
{
	ft_select_function(p, v);
	ft_malloc_static(p, v);
	if ((*v)->minus)
		ft_left_adjusted(p, v);
	else
		ft_right_adjusted(p, v);
	ft_free(p, v);
}

int			ft_string_spag(t_ptf *p, t_verify **v)
{
	int		i;
	char	*str;

	i = 0;
	str = "(null)";
	if ((*v)->dot && (*v)->pwidth < 6)
	{
		while (i < (*v)->pwidth)
		{
			(*p).tmp[i] = str[i];
			i++;
		}
		(*p).tmp[i] = '\0';
		return (i);
	}
	else
		while (str[i] != '\0')
		{
			(*p).tmp[i] = str[i];
			i++;
		}
	(*p).tmp[i] = '\0';
	return (i);
}

int			ft_wchar_spag(t_ptf *p, t_verify **v)
{
	int		i;
	int		ret;
	int		sum;

	i = 0;
	sum = 0;
	while ((*p).wchar[i])
	{
		ret = ft_char_itoa((intmax_t)(*p).wchar[i], p, v);
		if (ret < 0)
			return (-1);
		sum += ret;
		if ((*v)->dot && sum > (*v)->pwidth)
		{
			sum -= ret;
			break ;
		}
		ft_wchar_foo(p, ret);
		i++;
	}
	return (sum);
}
