/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:41:38 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/20 19:14:11 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in(char *line, t_in *p, t_rooms *r)
{
	if (p->noa == 0)
		ft_parse_noa(line, p);
	else if (line[0] == '#')
		ft_find_command(line, p);
	else if (p->start == 1)
		ft_parse_start_room(line, p, r);
	else if (p->end == 1)
		ft_parse_end_room(line, p, r);
	else if (p->start == 2 && p->end == 2)
		ft_parse_links(line, p, r);
	else if (p->noa != 0 && p->end_l == 0)
		ft_parse_rooms(line, r);
	else
		ft_errors("insufficient data.");
}
