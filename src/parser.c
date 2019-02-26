/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:21:06 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:33:06 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			parser(t_data *d)
{
	int			psn;
	t_room		*head;

	psn = 0;
	head = NULL;
	look_for_ants(d, &psn);
	rooms(d, &head, &psn);
	path(d, &head, &psn);
	algorithm(d, &head);
	free_room_print(d, &head, NULL, 0);
	free_matrix(d, d->matrix_len);
	free(d->prev);
	free(d->dist);
	free(d->result);
	return (0);
}
