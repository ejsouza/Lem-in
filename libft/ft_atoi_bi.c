/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:53:33 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 14:59:43 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isnumb(int c)
{
	if ((c > 47) && (c < 58))
		return (1);
	else
		return (0);
}

static long long	ft_get_atoi_result(const char *s, int *ptr)
{
	int			i;
	int			number;
	long long	result;

	i = *ptr;
	number = 0;
	result = 0;
	while (ft_isnumb(s[i]))
	{
		number = s[i] - '0';
		if (s[i + 1] != '\0' && ft_isnumb(s[i + 1]))
		{
			result += number;
			result *= 2;
		}
		i++;
	}
	return (result + number);
}

static int			ft_check(const char *str)
{
	int i;
	int	flag;
	int	len;

	i = 0;
	flag = 1;
	len = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		(str[i] == '-') ? (flag = -1) : flag;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '1')
	{
		len++;
		i++;
	}
	if (len > 18 && flag < 0)
		return (0);
	if (len > 18 && flag == 1)
		return (-1);
	return (1);
}

int					ft_atoi_bi(const char *str)
{
	int			i;
	int			flag;
	int			check;
	long long	result;

	i = 0;
	flag = 1;
	check = ft_check(str);
	result = 0;
	if (check == 0 || check == -1)
		return (check);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	if (str[i] == '+' && flag > 0)
		i++;
	result = ft_get_atoi_result(str, &i);
	return ((int)result * flag);
}
