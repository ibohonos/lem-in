/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:41:38 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/21 23:05:26 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in(char *line, t_in *p, t_rooms *r)
{
	if (p->noa == 0)
		ft_parse_noa(line, p);
	else if (p->start == 0)
		ft_parse_start(line, p);
	else if (p->start > 0 && p->end == 0)
		ft_parse_rooms(line, p, r);
	else if (p->start > 0 && p->end > 0)
		ft_parse_end_room(line, p, r);
	else if (p->end_r == 1)
		ft_parse_links(line, p, r);
}
