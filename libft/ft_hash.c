/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:45:27 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:28:43 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_hexa_prefix(t_ptf *p, t_verify **v)
{
	int		i;
	char	ch;

	if ((*p).va_uns_int != 0 && (*v)->hash == 1 && (*p).type != 'o' &&
		(*p).type != 'O')
	{
		ch = ((*p).type == 'x') ? 'x' : 'X';
		if (!((*p).tab = (char *)malloc(sizeof(char) * (*p).x + 1)))
			return (1);
		(*p).tab[(*p).x] = '\0';
		(*p).tab = ft_memmove((*p).tab, (*v)->target, (*p).x);
		(*v)->target[0] = '0';
		(*v)->target[1] = ch;
		(*p).len = ((*v)->widthnum <= (*v)->pwidth) ? (*p).x : ((*p).x - 2);
		i = 0;
		while (i < (*p).len)
		{
			(*v)->target[i + 2] = (*p).tab[i];
			i++;
		}
		(*p).x = i + 2;
		(*v)->target[(*p).x] = '\0';
		free((*p).tab);
	}
	return (0);
}

static int		ft_bar(t_ptf *p, t_verify **v)
{
	int		i;
	char	ch;
	char	*tmp;

	i = ft_strlen((*v)->target);
	ch = ((*p).type == 'x') ? 'x' : 'X';
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (1);
	tmp[i] = '\0';
	tmp = ft_memmove(tmp, (*v)->target, i);
	(*v)->target[0] = '0';
	(*v)->target[1] = ch;
	i = 0;
	while (tmp[i])
	{
		(*v)->target[i + 2] = tmp[i];
		i++;
	}
	(*p).x = i + 2;
	(*v)->target[i + 2] = '\0';
	free(tmp);
	return (0);
}

static void		ft_zero_mode(t_ptf *p, t_verify **v)
{
	int		i;
	char	ch;

	i = 0;
	ch = ((*p).type == 'x') ? 'x' : 'X';
	while ((*v)->target[i] == '0')
		i++;
	if (i > 1)
		(*v)->target[1] = ch;
	else
		ft_bar(p, v);
}

static void		ft_space_mode(t_ptf *p, t_verify **v)
{
	int		i;
	char	ch;

	i = 0;
	ch = ((*p).type == 'x') ? 'x' : 'X';
	while ((*v)->target[i] == ' ')
		i++;
	if (i > 1)
	{
		i--;
		(*v)->target[i] = ch;
		i--;
		(*v)->target[i] = '0';
	}
	else
		ft_bar(p, v);
}

void			ft_hash(t_ptf *p, t_verify **v)
{
	if ((*v)->hash && (*p).va_uns_int != 0 && ((*p).type == 'x' ||
				(*p).type == 'X'))
	{
		if ((*v)->target[0] == '0' && (*v)->widthnum > (*v)->pwidth)
			ft_zero_mode(p, v);
		else if ((*v)->target[0] == ' ')
			ft_space_mode(p, v);
		else
			ft_bar(p, v);
	}
	else if ((*v)->hash && ((*p).type == 'o' || (*p).type == 'O'))
	{
		ft_oct(p, v);
	}
}
