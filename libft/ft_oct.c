/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 11:46:03 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:38:51 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		bar(t_ptf *p, t_verify **v)
{
	int		i;
	int		k;
	char	*tmp;

	i = (*p).x;
	k = 1;
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
		return (1);
	tmp[i] = '\0';
	ft_bzero(tmp, i + 1);
	if ((*v)->target[i - 1] == ' ')
		i--;
	tmp = ft_memmove(tmp, (*v)->target, i);
	if ((*v)->target[0] != '0')
	{
		(*v)->target[0] = '0';
		k = 1;
		i = 0;
		while (tmp[i])
			(*v)->target[k++] = tmp[i++];
	}
	(*p).x = (k > i) ? k : i;
	(*v)->target[(*p).x] = '\0';
	free(tmp);
	return (0);
}

int				ft_oct(t_ptf *p, t_verify **v)
{
	int	i;

	if ((*v)->hash && (*p).va_uns_int == 0 && ((*p).type == 'o' ||
				(*p).type == 'O') && (*v)->dot == 1 && (*v)->pwidth == -1)
	{
		(*v)->target[0] = '0';
		(*p).x = 1;
	}
	if ((*v)->hash && (*p).va_uns_int != 0 && ((*p).type == 'o' ||
				(*p).type == 'O'))
	{
		i = 0;
		if ((*v)->minus || (*v)->target[0] != ' ')
			bar(p, v);
		else if ((*v)->target[0] == ' ')
		{
			while ((*v)->target[i] == ' ')
				i++;
			i--;
			(*v)->target[i] = '0';
		}
	}
	return (0);
}

int				ft_void(t_ptf *p)
{
	int	i;

	if ((*p).type != 'p')
		return (1);
	i = (*p).len + 1;
	(*p).tmp[i + 1] = '\0';
	while (i)
	{
		(*p).tmp[i] = (*p).tmp[i - 2];
		i--;
	}
	(*p).tmp[0] = '0';
	(*p).tmp[1] = 'x';
	(*p).len += 2;
	return (0);
}
