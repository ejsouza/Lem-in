/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:28:29 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:29:15 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_print_error_exit(t_data *d, char *s)
{
	if ((*d).data != NULL)
	{
		free((*d).data);
		(*d).data = NULL;
	}
	ft_printf("ERROR, %s\n", s);
	exit(EXIT_FAILURE);
}

int		is_a_link(t_data *d, int *psn)
{
	int		i;
	_Bool	flag;

	i = *psn;
	flag = ((*d).data[*psn] == '#') ? 1 : 0;
	while ((*d).data[i] && (*d).data[i] != '\n')
	{
		if ((*d).data[i] == '-' && !flag)
		{
			if ((i > 0) && !ft_space_or_tab((*d).data[i - 1]) &&
					!ft_space_or_tab((*d).data[i + 1]))
			{
				(*d).link = 1;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		look_for_ants(t_data *d, int *psn)
{
	if (!ft_isdigit((*d).data[*psn]))
		free_print_error_exit(d, "No ants found");
	if (ft_isdigit((*d).data[*psn]) || ft_plus_minus((*d).data[*psn]))
	{
		d->ants = ft_atoi_long_int(&(*d).data[*psn]);
		if (d->ants < 1 || d->ants > INT_MAX)
			free_print_error_exit(d, "too few/many ants");
		while (ft_isdigit((*d).data[*psn]))
			(*psn)++;
		if ((*d).data[*psn] == '\n')
			(*psn)++;
	}
	return (0);
}
