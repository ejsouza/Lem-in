/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:14:31 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:48:34 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_select_function(t_ptf *p, t_verify **v)
{
	if ((*p).type == 'i' || (*p).type == 'd' || (*p).type == 'D')
		ft_int(p, v);
	else if ((*p).type == 'x' || (*p).type == 'X' || (*p).type == 'o' ||
			(*p).type == 'O')
		ft_hexadecimal(p, v);
	else if ((*p).type == 'u' || (*p).type == 'U')
		ft_unsigned_int(p, v);
	else if ((*p).type == 'c' || (*p).type == 'C')
		ft_char(p, v);
	else if ((*p).type == 's' || (*p).type == 'S')
		ft_ptr(p, v);
	else if ((*p).type == 'p')
		ft_hexadecimal(p, v);
}
