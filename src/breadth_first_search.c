/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:24:29 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:26:00 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	free_the_hell_out_of_me(t_data *d, t_room **head)
{
	ft_printf("Error, the rooms are not connected from start to end\n");
	free_room_print(d, head, "Error, onnection not found from start to end\n",
			0);
	free_matrix(d, d->matrix_len);
	free(d->prev);
	free(d->dist);
	free(d->data);
	exit(EXIT_FAILURE);
}

static void	malloc_initialize_arrays(t_data *d)
{
	int	i;

	i = 0;
	if (!(d->prev = (int *)malloc(sizeof(int) * d->matrix_len)))
		exit(EXIT_FAILURE);
	if (!(d->dist = (int *)malloc(sizeof(int) * d->matrix_len)))
		exit(EXIT_FAILURE);
	while (++i < d->matrix_len)
	{
		d->prev[i] = -1;
		d->dist[i] = -1;
	}
	d->prev[d->idx_start] = d->idx_start;
	d->dist[d->idx_start] = 0;
}

char		*name_room(t_room **head, int number)
{
	t_room *tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->room_nb == number)
			return (tmp->room);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	reconstructing_path(t_data *d, t_room **head)
{
	int	bastard;
	int	foo;
	int	bar;
	int	i;

	i = -1;
	foo = d->dist[d->idx_end];
	if (foo < 1)
		free_the_hell_out_of_me(d, head);
	if (!(d->result = (int *)malloc(sizeof(int) * (foo + 1))))
		exit(EXIT_FAILURE);
	while (++i <= foo)
		d->result[i] = -1;
	d->result[foo] = d->idx_end;
	d->result[--foo] = d->prev[d->idx_end];
	bar = d->prev[d->idx_end];
	while (--foo >= 0)
	{
		bastard = 0;
		while (bastard < bar)
			bastard++;
		bar = d->prev[bastard];
		d->result[foo] = d->prev[bastard];
	}
}

void		breadth_first_search(t_data *d, t_room **head, t_queue **front,
		t_queue **rear)
{
	int	u;
	int	v;

	malloc_initialize_arrays(d);
	while (!is_queue_empty(front))
	{
		u = return_head(front);
		dequeue(front);
		v = -1;
		while (++v < d->matrix_len)
			if (d->dist[v] == -1 && d->matrix[u][v] > 0)
			{
				d->dist[v] = d->dist[u] + 1;
				d->prev[v] = u;
				enqueue(front, rear, v);
			}
	}
	reconstructing_path(d, head);
}
