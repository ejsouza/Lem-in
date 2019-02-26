/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 09:51:38 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:05:05 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_wchar_foo(t_ptf *p, int ret)
{
	int		i;

	i = 0;
	while (i < ret)
	{
		(*p).arr[(*p).k] = (*p).tmp[i];
		(*p).k++;
		i++;
	}
}

static void		bar(t_ptf *p, int *sum)
{
	int		i;

	i = 0;
	while (i < *(sum) && (*p).arr[i] != '\0')
	{
		(*p).tmp[i] = (*p).arr[i];
		i++;
	}
	(*p).tmp[i] = '\0';
}

static int		ft_handle_null(t_ptf *p)
{
	int		i;
	int		k;
	char	*tmp;

	tmp = "(null)";
	i = 0;
	k = 0;
	while ((*p).buff[i])
		i++;
	while (tmp[k])
	{
		(*p).buff[i] = tmp[k];
		i++;
		k++;
	}
	(*p).j += 6;
	return (0);
}

int				ft_wchar(t_ptf *p, t_verify **v)
{
	int	sum;

	if ((*p).wchar == NULL)
		return (ft_handle_null(p));
	sum = ft_wchar_spag(p, v);
	if (sum < 0)
		return (-1);
	if ((*v)->dot > 0)
	{
		if ((*v)->pwidth < 0)
		{
			(*p).nb = 0;
			return (0);
		}
		sum = (sum < (*v)->pwidth) ? sum : (*v)->pwidth;
	}
	bar(p, &sum);
	return (sum);
}
