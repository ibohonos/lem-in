/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:54:05 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/13 19:25:01 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init_in(t_in *p)
{
	p->noa = 0;
	p->start = 0;
	p->end = 0;
	p->end_r = 0;
	p->end_l = 0;
	p->gc = 0;
	p->room_nbr = 0;
	p->len_way = 0;
	p->start_room = NULL;
	p->end_room = NULL;
	p->way = NULL;
}
