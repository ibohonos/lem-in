/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:34:25 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/20 19:08:14 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_in
{
	uintmax_t		noa;
	int				start;
	int				end;
	int				end_r;
	int				end_l;
	int				gc;
	uintmax_t		room_nbr;
	intmax_t		len_way;
	struct s_rooms	*start_room;
	struct s_rooms	*end_room;
	struct s_links	*way;
}					t_in;

typedef struct		s_links
{
	struct s_rooms	*room;
	struct s_links	*next;
}					t_links;

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	uintmax_t		ant;
	int				free;
	struct s_links	*link;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_map
{
	char			***map;
	int				x;
	int				y;
}					t_map;

void				ft_parse_start_room(char *line, t_in *p, t_rooms *r);
int					ft_send_new_ants(t_in *p, uintmax_t *ant, int res);
void				ft_parse_end_room(char *line, t_in *p, t_rooms *r);
void				ft_parse_start(char *line, t_in *p, t_rooms *r);
void				ft_parse_links(char *line, t_in *p, t_rooms *r);
void				ft_find_links(char *s1, char *s2, t_rooms *r);
void				ft_print_send_ants(t_in *p, uintmax_t *ant);
void				lem_in(char *line, t_in *p, t_rooms *r);
void				ft_parse_rooms(char *line, t_rooms *r);
void				ft_find_command(char *line, t_in *p);
void				ft_find_road(t_in *p, t_rooms *r);
void				ft_parse_noa(char *line, t_in *p);
t_links				*ft_swap_way(t_links *way);
void				ft_init_rooms(t_rooms *r);
void				ft_error_room(char **arr);
void				ft_errors(char *error);
int					ft_send_ants(t_in *p);
void				ft_init_in(t_in *p);

#endif
