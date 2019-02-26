/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:33:18 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:35:40 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		valid(int c)
{
	if ((c > 32) && (c < 127))
		return (1);
	return (0);
}

static int		check_link(t_data *d, t_room **head, int *psn)
{
	int	i;
	int	flag;

	i = *psn - 1;
	flag = 0;
	while ((*d).data[++i] && !isspace((*d).data[i]))
	{
		if (((*d).data)[i] == '-')
		{
			if (!valid((*d).data[i - 1]) || !valid((*d).data[i + 1]))
			{
				free_room_print(d, head, "links fail", 1);
			}
			flag++;
		}
	}
	if (flag != 1)
		free_room_print(d, head, "links fail", 1);
	return (0);
}

int				path(t_data *d, t_room **head, int *psn)
{
	create_matrix(d, head);
	while ((*d).data[*psn])
	{
		check_link(d, head, psn);
		set_index(d, head, psn);
	}
	if (!d->start_r || !d->end_r)
		free_room_print(d, head, "did not found room linking start/end", 1);
	return (0);
}
