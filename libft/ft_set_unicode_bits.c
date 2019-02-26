/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_unicode_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:21:24 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:50:13 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_set_unicode_bits(t_ptf *p, t_bits **c, short func)
{
	if (func == 3)
	{
		(*p).tmp[0] = (unsigned char)ft_atoi_bi((*c)->c3);
		(*p).tmp[1] = (unsigned char)ft_atoi_bi((*c)->local2);
		(*p).tmp[2] = (unsigned char)ft_atoi_bi((*c)->local3);
	}
	else if (func == 4)
	{
		(*p).tmp[0] = (unsigned char)ft_atoi_bi((*c)->c4);
		(*p).tmp[1] = (unsigned char)ft_atoi_bi((*c)->local2);
		(*p).tmp[2] = (unsigned char)ft_atoi_bi((*c)->local3);
		(*p).tmp[3] = (unsigned char)ft_atoi_bi((*c)->local4);
	}
}
