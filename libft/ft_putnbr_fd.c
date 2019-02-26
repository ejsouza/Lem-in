/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puntnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:42:14 by esouza            #+#    #+#             */
/*   Updated: 2017/11/23 11:10:38 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			flag;
	char		ch;

	nb = n;
	if (nb < 0)
	{
		flag = -1;
		nb *= flag;
		write(fd, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb >= 0 && nb <= 9)
	{
		ch = nb + '0';
		write(fd, &ch, 1);
	}
}
