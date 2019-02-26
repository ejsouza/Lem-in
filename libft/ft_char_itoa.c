/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:17:42 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 15:05:15 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_set_bits(t_bits *c)
{
	(*c).c4[0] = '1';
	(*c).c4[1] = '1';
	(*c).c4[2] = '1';
	(*c).c4[3] = '1';
	(*c).c4[4] = '0';
	(*c).c4[8] = 0;
	(*c).c3[0] = '1';
	(*c).c3[1] = '1';
	(*c).c3[2] = '1';
	(*c).c3[3] = '0';
	(*c).c3[8] = 0;
	(*c).c2[0] = '1';
	(*c).c2[1] = '1';
	(*c).c2[2] = '0';
	(*c).c2[8] = 0;
	(*c).local2[0] = '1';
	(*c).local2[1] = '0';
	(*c).local2[8] = 0;
	(*c).local3[0] = '1';
	(*c).local3[1] = '0';
	(*c).local3[8] = 0;
	(*c).local4[0] = '1';
	(*c).local4[1] = '0';
	(*c).local4[8] = 0;
}

static	int			ft_two_bytes(t_ptf *p)
{
	int		len;
	int		i;
	t_bits	*c;

	if (!(c = (t_bits *)malloc(sizeof(t_bits))))
		return (1);
	ft_set_bits(c);
	i = 7;
	len = ft_strlen((*p).tmp) - 1;
	while (i > 1)
		c->local2[i--] = (*p).tmp[len--];
	i = 7;
	while (len >= 0)
		c->c2[i--] = (*p).tmp[len--];
	while (i > 2)
		c->c2[i--] = '0';
	(*p).tmp[0] = (unsigned char)ft_atoi_bi(c->c2);
	(*p).tmp[1] = (unsigned char)ft_atoi_bi((*c).local2);
	free(c);
	(*p).tmp[2] = 0;
	return (2);
}

static	int			ft_three_bytes(t_ptf *p)
{
	int		len;
	int		i;
	t_bits	*c;

	if (!(c = (t_bits *)malloc(sizeof(t_bits))))
		return (1);
	ft_set_bits(c);
	i = 7;
	len = ft_strlen((*p).tmp) - 1;
	while (i > 1)
		c->local3[i--] = (*p).tmp[len--];
	i = 7;
	while (i > 1)
		c->local2[i--] = (*p).tmp[len--];
	i = 7;
	while (len >= 0)
		c->c3[i--] = (*p).tmp[len--];
	while (i > 2)
		c->c3[i--] = '0';
	ft_set_unicode_bits(p, &c, 3);
	free(c);
	(*p).tmp[3] = 0;
	return (3);
}

static	int			ft_four_bytes(t_ptf *p)
{
	t_bits	*c;

	if (!(c = (t_bits *)malloc(sizeof(t_bits))))
		return (1);
	ft_set_bits(c);
	(*c).len = ft_strlen((*p).tmp) - 1;
	(*c).i = 7;
	while ((*c).i > 1)
		c->local4[(*c).i--] = (*p).tmp[(*c).len--];
	(*c).i = 7;
	while ((*c).i > 1)
		c->local3[(*c).i--] = (*p).tmp[(*c).len--];
	(*c).i = 7;
	while ((*c).i > 1)
		(*c).local2[(*c).i--] = (*p).tmp[(*c).len--];
	(*c).i = 7;
	while ((*c).len >= 0)
		c->c4[(*c).i--] = (*p).tmp[(*c).len--];
	while ((*c).i > 3)
		c->c4[(*c).i--] = '0';
	ft_set_unicode_bits(p, &c, 4);
	free(c);
	(*p).tmp[4] = 0;
	return (4);
}

int					ft_char_itoa(intmax_t n, t_ptf *p, t_verify **v)
{
	short	len;

	if (n == '\0' && (*v)->dot == 1)
		(*v)->pwidth = 0;
	if ((*p).type == 'c' && n < 128)
		return (ft_one_byte(p, n));
	if (((n >= 0xd800 && n <= 0xdfff) || (n < 0x0000) || (n > 0x10FFFF)))
	{
		(*p).nb = -1;
		return (-1);
	}
	ft_unsigned_itoa(n, "01", p, v);
	len = ft_strlen((*p).tmp);
	if (n < 128)
		return (ft_one_byte(p, n));
	else if (len < 12)
		return (ft_two_bytes(p));
	else if (len < 17)
		return (ft_three_bytes(p));
	else if (len < 22)
		return (ft_four_bytes(p));
	return (-1);
}
