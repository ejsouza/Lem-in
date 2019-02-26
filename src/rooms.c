/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:37:57 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:40:14 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		check_coordinate(t_data *d, t_room **head, int *psn)
{
	int	count;
	int	number;

	if ((*d).data[*psn] == '\0')
		free_room_print(d, head, "No coordinates found", 1);
	count = (ft_space_or_tab((*d).data[*psn] == 1)) ? 1 : 0;
	(*psn) += count;
	while ((*d).data[*psn] && (*d).data[*psn] != '\n')
	{
		if (ft_space_or_tab((*d).data[*psn]))
			count++;
		else if (ft_isdigit((*d).data[*psn]) || ft_plus_minus((*d).data[*psn]))
		{
			number = ft_atoi_long_int(&(*d).data[*psn]);
			(*psn) += ft_intlen(number);
			(*psn)--;
		}
		else if (!ft_isdigit((*d).data[*psn]))
			free_room_print(d, head, "should be only nb in coord", 1);
		(*psn)++;
	}
	(*psn)++;
	if (count != 2)
		free_room_print(d, head, "bad spacing around coordinates", 1);
}

void		check_for_duplicate(t_data *d, t_room **head, char *s)
{
	t_room *tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->room, s) == 0)
			free_room_print(d, head, "found  duplicated room", 1);
		tmp = tmp->next;
	}
}

int			insert_front(t_data *d, t_room **head, int *psn)
{
	t_room		*node;
	int			i;

	i = 0;
	d->room_nb++;
	if (!(node = (t_room *)malloc(sizeof(t_room))))
		return (1);
	while ((*d).data[*psn] && !ft_space_or_tab((*d).data[*psn]))
		node->room[i++] = (*d).data[(*psn)++];
	node->room[i] = '\0';
	node->next = NULL;
	node->room_nb = d->room_nb;
	check_for_duplicate(d, head, node->room);
	check_coordinate(d, head, psn);
	if (*head != NULL)
		node->next = *head;
	*head = node;
	return (0);
}

static int	get_rooms(t_data *d, t_room **head, int *psn)
{
	if ((*d).data[*psn] == 'L')
		free_room_print(d, head, "Rooms shall not start with 'L'", 1);
	insert_front(d, head, psn);
	return (0);
}

int			rooms(t_data *d, t_room **head, int *psn)
{
	d->room_nb = -1;
	while ((*d).data[*psn] && !is_a_link(d, psn))
	{
		if ((*d).data[*psn] == '#')
			which_command(d, head, psn);
		else if (ft_isspace((*d).data[*psn]))
			free_room_print(d, head, "space not allowed", 1);
		else if ((*d).data[*psn] != '#')
			get_rooms(d, head, psn);
	}
	if (!(*d).link)
		free_room_print(d, head, "No link to rooms found", 1);
	else if ((*d).start < 0 || (*d).end < 0)
	{
		free_room_print(d, head, "No start/end room found", 1);
	}
	return (0);
}
