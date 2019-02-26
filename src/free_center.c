/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:27:41 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:28:12 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_matrix(t_data *d, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		free((*d).matrix[i]);
		(*d).matrix[i] = NULL;
	}
	free((*d).matrix);
	(*d).matrix = NULL;
}

void		free_room_list(t_room **head)
{
	t_room *tmp;

	while (*head != NULL)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}

void		free_room_print(t_data *d, t_room **head, char *s, _Bool error)
{
	if (*head != NULL)
	{
		free_room_list(head);
		*head = NULL;
	}
	if ((*d).data != NULL)
	{
		free((*d).data);
		(*d).data = NULL;
	}
	if (error)
	{
		ft_printf("ERROR, %s\n", s);
		exit(EXIT_FAILURE);
	}
}
