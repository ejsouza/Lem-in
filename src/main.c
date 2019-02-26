/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:05:29 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 12:00:58 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		skip_garbage(char **tmp)
{
	if (ft_strcmp(*tmp, "##start") == 0)
		return (0);
	else if (ft_strcmp(*tmp, "##end") == 0)
		return (0);
	return (1);
}

static void		update_data(t_data *d, char **tmp)
{
	char	*ltmp;
	int		i;
	int		len;

	if (*tmp[0] == '#' && skip_garbage(tmp))
		return ;
	i = -1;
	len = ft_strlen((*d).data) + 2;
	if (!(ltmp = (char *)malloc(sizeof(char) * len)))
		exit(EXIT_FAILURE);
	ft_bzero(ltmp, len);
	if ((*d).data != NULL)
	{
		ltmp = ft_strcpy(ltmp, (*d).data);
		while (ltmp[++i])
			;
		ltmp[i] = '\n';
		free((*d).data);
		(*d).data = NULL;
	}
	(*d).data = ft_strjoin(ltmp, *tmp);
	free(ltmp);
	ltmp = NULL;
}

static int		get_data(t_data *d)
{
	char	*tmp;

	tmp = NULL;
	while (get_next_line(0, &tmp))
	{
		update_data(d, &tmp);
		free(tmp);
		tmp = NULL;
	}
	if ((*d).data == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (tmp != NULL)
		free(tmp);
	return (0);
}

static void		initialize_data(t_data *d)
{
	d->data = NULL;
	d->ants = 0;
	d->idx_end = 0;
	d->idx_start = 0;
	d->start = -1;
	d->end = -1;
	d->link = 0;
	d->valid = 0;
	d->invalid = 0;
	d->start_r = 0;
	d->end_r = 0;
	d->room_nb = -1;
	d->start_room[0] = '\0';
	d->end_room[0] = '\0';
	d->prev = NULL;
	d->dist = NULL;
	d->result = NULL;
}

int				main(void)
{
	t_data d;

	initialize_data(&d);
	get_data(&d);
	parser(&d);
	if (d.data != NULL)
		free(d.data);
	return (0);
}
