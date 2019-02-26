/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:43:01 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:45:03 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	insert_head_end(t_data *d, t_room **head, char *s)
{
	t_room	*tmp;
	t_room	*node;
	int		i;

	d->room_nb++;
	check_for_duplicate(d, head, s);
	i = 0;
	tmp = *head;
	if (!(node = (t_room *)malloc(sizeof(t_room))))
		return (1);
	while ((node->room[i] = s[i]))
		i++;
	node->room[i] = '\0';
	node->room_nb = d->room_nb;
	node->next = NULL;
	if (*head != NULL)
		node->next = *head;
	*head = node;
	return (0);
}

static int	set_start_point(t_data *d, t_room **head, int *psn)
{
	int	i;

	if ((*d).start > 0)
		free_room_print(d, head, "found a duplicated start, aborting...", 1);
	i = 0;
	(*psn) += 7;
	(*d).start = 1;
	while ((*d).data[*psn] && (*d).data[*psn] != '\n')
		(*psn)++;
	(*psn)++;
	if (ft_isspace((*d).data[*psn]))
		free_room_print(d, head, "space not allowed here", 1);
	while ((*d).data[*psn] && !ft_space_or_tab((*d).data[*psn]) &&
			(*d).data[*psn] != '\n')
		(*d).start_room[i++] = (*d).data[(*psn)++];
	(*d).start_room[i] = '\0';
	check_coordinate(d, head, psn);
	insert_head_end(d, head, (*d).start_room);
	return (0);
}

static int	set_end_point(t_data *d, t_room **head, int *psn)
{
	int	i;

	if ((*d).end > 0)
		free_room_print(d, head, "found a duplicated end, aborting...", 1);
	i = 0;
	(*psn) += 5;
	(*d).end = 1;
	while ((*d).data[*psn] && (*d).data[*psn] != '\n')
		(*psn)++;
	(*psn)++;
	if (ft_isspace((*d).data[*psn]))
		free_room_print(d, head, "space not allowed here", 1);
	while ((*d).data[*psn] && !ft_space_or_tab((*d).data[*psn]) &&
			(*d).data[*psn] != '\n')
		(*d).end_room[i++] = (*d).data[(*psn)++];
	(*d).end_room[i] = '\0';
	check_coordinate(d, head, psn);
	insert_head_end(d, head, (*d).end_room);
	return (0);
}

int			which_command(t_data *d, t_room **head, int *psn)
{
	if (ft_strncmp(&(*d).data[*psn], "##start", 7) == 0)
	{
		set_start_point(d, head, psn);
		d->idx_start = d->room_nb;
	}
	else if (ft_strncmp(&(*d).data[*psn], "##end", 5) == 0)
	{
		d->idx_end = d->room_nb + 1;
		set_end_point(d, head, psn);
	}
	return (0);
}
