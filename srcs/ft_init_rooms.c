/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 22:51:06 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/21 22:53:30 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init_rooms(t_rooms *r)
{
	r->name = NULL;
	r->x = -1;
	r->y = -1;
	r->link = NULL;
	r->next = NULL;
	r->prev = NULL;
}