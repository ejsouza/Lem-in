/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:26:20 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:27:19 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	list_length(t_room **head)
{
	int		length;
	t_room	*tmp;

	length = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}

int			create_matrix(t_data *d, t_room **head)
{
	int	i;
	int	j;

	i = -1;
	d->matrix_len = list_length(head);
	if (!((*d).matrix = (int **)malloc(sizeof(int *) * d->matrix_len)))
		free_room_print(d, head, "fail to malloc matrix", 1);
	while (++i < d->matrix_len)
		if (!((*d).matrix[i] = (int *)malloc(sizeof(int) * d->matrix_len)))
			free_room_print(d, head, "fail to malloc matrix", 1);
	i = -1;
	while (++i < d->matrix_len)
	{
		j = -1;
		while (++j < d->matrix_len)
			(*d).matrix[i][j] = 0;
	}
	return (d->matrix_len);
}
