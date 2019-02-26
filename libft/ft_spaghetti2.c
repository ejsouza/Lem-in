/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaghetti2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 12:52:46 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:15:54 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_pre_precision_spag(t_ptf *p, t_verify **v)
{
	int		i;

	i = 0;
	if ((*p).va_ptr == NULL && (*p).type == 's')
		return (0);
	while ((*v)->pwidth > (*p).len)
	{
		(*v)->target[i] = '0';
		i++;
		(*p).len++;
	}
	return (i);
}
