/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:36:19 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:37:39 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		enqueue(t_queue **front, t_queue **rear, int index)
{
	t_queue *new_queue;

	if (!(new_queue = (t_queue *)malloc(sizeof(t_queue))))
		exit(EXIT_FAILURE);
	new_queue->index = index;
	new_queue->next = NULL;
	if (*front == NULL)
	{
		*front = new_queue;
		*rear = new_queue;
	}
	else
	{
		(*rear)->next = new_queue;
		*rear = new_queue;
	}
}

void		dequeue(t_queue **front)
{
	t_queue *tmp;

	if (*front == NULL)
		return ;
	tmp = *front;
	*front = (*front)->next;
	free(tmp);
}

int			return_head(t_queue **front)
{
	if (*front != NULL)
		return ((*front)->index);
	return (-1);
}

_Bool		is_queue_empty(t_queue **front)
{
	if (*front == NULL)
		return (1);
	return (0);
}
