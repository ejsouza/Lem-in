/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:24:04 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:24:12 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		algorithm(t_data *d, t_room **head)
{
	t_queue	*front;
	t_queue	*rear;

	front = NULL;
	rear = NULL;
	enqueue(&front, &rear, d->idx_start);
	breadth_first_search(d, head, &front, &rear);
	ft_printf("%s\n\n", d->data);
	print(d, head);
	return (0);
}
