/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:18:22 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:58:51 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_free(t_ptf *p, t_verify **v)
{
	free((*v)->target);
	free((*p).tmp);
	free((*p).arr);
}

int				ft_malloc_static(t_ptf *p, t_verify **v)
{
	size_t		size;

	size = 128;
	if ((*v)->widthnum > 0)
		size += (*v)->widthnum;
	if ((*v)->pwidth > 0)
		size += (*v)->pwidth;
	if ((*p).ptrlen > 0)
		size += (*p).ptrlen;
	if (!((*v)->target = (char *)malloc(sizeof(char) * size + 1)))
		return (1);
	if (!((*p).tmp = (char *)malloc(sizeof(char) * size + 1)))
		return (1);
	if (!((*p).arr = (char *)malloc(sizeof(char) * size + 1)))
		return (1);
	return (0);
}

static int		ft_foo_spag(t_ptf *p, int k)
{
	int	i;
	int	j;

	i = 0;
	j = k;
	while (i < j)
	{
		(*p).tmp[i] = (*p).va_ptr[i];
		i++;
	}
	(*p).tmp[i] = '\0';
	return (i);
}

int				ft_string(t_ptf *p, t_verify **v)
{
	short		i;
	short		k;

	k = ((*v)->dot == 1) ? (*v)->pwidth : 0;
	i = 0;
	if ((*p).va_ptr == NULL)
		return (ft_string_spag(p, v));
	else if ((*p).va_ptr[0] == '\0' && (*v)->dot == 1)
		(*v)->pwidth = 0;
	else if (k && (*p).va_ptr[0] != '\0')
	{
		if ((*v)->pwidth > (short)ft_strlen((*p).va_ptr))
		{
			(*v)->pwidth = ft_strlen((*p).va_ptr);
			k = (*v)->pwidth;
		}
		if (i < k)
			i = ft_foo_spag(p, k);
		return (i);
	}
	while (((*p).tmp[i] = (*p).va_ptr[i]))
		i++;
	(*p).tmp[i] = '\0';
	return (i);
}
