/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 10:59:17 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:01:12 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	calculate(char **s, int i)
{
	int				control;
	long int		number;
	unsigned int	conv;

	control = 0;
	number = 0;
	conv = 0;
	while (ft_isdigit((*s)[i]))
	{
		conv = (*s)[i] - '0';
		if (control > 10)
			break ;
		number = (number * 10) + conv;
		i++;
		control++;
	}
	return (number);
}

long		ft_atoi_long_int(char *s)
{
	int			i;
	short		flag;
	long int	result;

	i = 0;
	result = 0;
	flag = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	result = calculate(&s, i);
	return (result * flag);
}
