/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_road.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:29:53 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/12 19:36:14 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_find_road(t_in *p, t_rooms *r)
{
	int i;

	while (r->start != 1)
		r = r->next;
	i = 1;
	p->noa = i;
}