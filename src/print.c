/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:35:54 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:36:07 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	top(t_data *d, t_room **head)
{
	int	ants;
	int	k;
	int	posit;
	int	boo;

	posit = 0;
	while (++posit < d->dist[d->idx_end])
	{
		ants = posit;
		boo = 1;
		k = posit;
		while (k)
		{
			if (boo > d->ants)
				break ;
			ft_printf("L%d-%s ", boo, name_room(head,
						d->result[ants]));
			k--;
			ants--;
			boo++;
		}
		ft_printf("\n");
	}
}

void		print(t_data *d, t_room **head)
{
	int	i;
	int	k;
	int	ants;
	int	anub;
	int	len;

	ants = 0;
	i = 0;
	k = 0;
	top(d, head);
	while (++ants <= d->ants)
	{
		anub = ants;
		len = d->dist[d->idx_end];
		ft_printf("L%d-%s ", ants, name_room(head, d->result[len]));
		while (--len > 0 && anub + 1 <= d->ants)
			ft_printf("L%d-%s ", ++anub, name_room(head,
						d->result[len]));
		ft_printf("\n");
	}
}
