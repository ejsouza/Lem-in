/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:40:33 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:42:39 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	look_for_index(t_data *d, t_room **head, char r1[], char r2[])
{
	int		x;
	int		y;
	t_room	*tmp;

	x = -1;
	y = -1;
	tmp = *head;
	while (tmp != NULL)
	{
		if (ft_strcmp(r1, tmp->room) == 0)
			x = tmp->room_nb;
		else if (ft_strcmp(r2, tmp->room) == 0)
			y = tmp->room_nb;
		if (x >= 0 && y >= 0)
			break ;
		tmp = tmp->next;
	}
	if (x >= 0 && y >= 0)
	{
		(*d).matrix[x][y] = 1;
		(*d).matrix[y][x] = 1;
	}
	else if (x < 0 || y < 0)
		free_room_print(d, head, "room unknown/not found", 1);
}

int			set_index(t_data *d, t_room **head, int *psn)
{
	int		i;
	char	sx[LEN_ROOM_NAME];
	char	sy[LEN_ROOM_NAME];

	i = 0;
	while ((*d).data[*psn] && (*d).data[*psn] != '-')
		sx[i++] = (*d).data[(*psn)++];
	sx[i] = '\0';
	i = 0;
	(*psn)++;
	while (!isspace((*d).data[(*psn)]) && (*d).data[*psn])
		sy[i++] = (*d).data[(*psn)++];
	sy[i] = '\0';
	if ((*d).data[*psn] == '\n')
		(*psn)++;
	if (ft_strcmp(sx, d->start_room) == 0 || ft_strcmp(sy, d->start_room) == 0)
		d->start_r++;
	if (ft_strcmp(sx, d->end_room) == 0 || ft_strcmp(sy, d->end_room) == 0)
		d->end_r++;
	look_for_index(d, head, &sx[0], &sy[0]);
	return (0);
}
