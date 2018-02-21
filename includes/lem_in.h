/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:34:25 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/21 21:15:08 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_in
{
	int			noa;
	int			start;
	int			end;
	int			end_r;
	int			end_l;
	char		**rooms;
	char		*links;
}				t_in;

void			ft_parse_end_room(char *line, t_in *p);
void			ft_parse_links(char *line, t_in *p);
void			ft_parse_start(char *line, t_in *p);
void			ft_parse_rooms(char *line, t_in *p);
void			ft_parse_noa(char *line, t_in *p);
void			lem_in(char *line, t_in *p);
void			ft_errors(char *error);
void			ft_init_in(t_in *p);

#endif
