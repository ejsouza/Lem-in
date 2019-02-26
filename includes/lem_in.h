/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:20:55 by esouza            #+#    #+#             */
/*   Updated: 2019/02/26 09:44:21 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define LEN_ROOM_NAME 128

# include "../libft/libft.h"

typedef struct		s_data
{
	char			*data;
	int				**matrix;
	int				*prev;
	int				*dist;
	int				*result;
	char			start_room[LEN_ROOM_NAME];
	char			end_room[LEN_ROOM_NAME];
	long			ants;
	int				idx_end;
	int				idx_start;
	short			valid;
	short			invalid;
	short			start;
	short			end;
	short			start_r;
	short			end_r;
	_Bool			link;
	int				room_nb;
	int				matrix_len;
}					t_data;

typedef struct		s_room
{
	char			room[LEN_ROOM_NAME];
	int				room_nb;
	struct s_room	*next;
}					t_room;

typedef struct		s_queue
{
	int				index;
	struct s_queue	*next;
}					t_queue;

int					main(void);
int					parser(t_data *d);
int					insert_front(t_data *d, t_room **head, int *psn);
int					look_for_ants(t_data *d, int *psn);
void				check_for_duplicate(t_data *d, t_room **head, char *s);
int					is_a_link(t_data *d, int *psn);
int					rooms(t_data *d, t_room **head, int *psn);
void				check_coordinate(t_data *d, t_room **head, int *psn);
int					which_command(t_data *d, t_room **head, int *psn);
void				free_room_list(t_room **head);
void				free_room_print(t_data *d, t_room **head, char *s,
		_Bool error);
void				free_matrix(t_data *d, int len);
int					path(t_data *d, t_room **head, int *psn);
int					create_matrix(t_data *d, t_room **head);
int					set_index(t_data *d, t_room **head, int *psn);
int					algorithm(t_data *d, t_room **head);
void				enqueue(t_queue **front, t_queue **rear, int index);
void				dequeue(t_queue **front);
int					return_head(t_queue **front);
_Bool				is_queue_empty(t_queue **front);
void				breadth_first_search(t_data *d, t_room **head,
		t_queue **front, t_queue **rear);
void				print(t_data *d, t_room **head);
char				*name_room(t_room **head, int number);

//fucking around
#endif
