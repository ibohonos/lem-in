/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:34:25 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/14 17:42:21 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_in
{
	int				noa;
	int				start;
	int				end;
	int				end_r;
	int				end_l;
	struct s_rooms	*start_room;
	struct s_rooms	*end_room;
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

void    			ft_parse_start_room(char *line, t_in *p, t_rooms *r);
void				ft_parse_end_room(char *line, t_in *p, t_rooms *r);
void				ft_parse_start(char *line, t_in *p, t_rooms *r);
void				ft_parse_links(char *line, t_in *p, t_rooms *r);
void				ft_find_links(char *s1, char *s2, t_rooms *r);
void				lem_in(char *line, t_in *p, t_rooms *r);
void				ft_parse_rooms(char *line, t_rooms *r);
void				ft_find_command(char *line, t_in *p);
void				ft_find_road(t_in *p, t_rooms *r);
void				ft_parse_noa(char *line, t_in *p);
void				ft_init_rooms(t_rooms *r);
void				ft_errors(char *error);
void				ft_init_in(t_in *p);

#endif
