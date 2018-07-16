/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_road.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:29:53 by ibohonos          #+#    #+#             */
/*   Updated: 2018/04/17 12:56:24 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_unvisit(t_rooms *r)
{
	while (r)
	{
		r->free = 1;
		r = r->next;
	}
}

static void	add_link_lst(t_links **list, t_rooms *r)
{
	t_links *tmp;
	t_links *new;

	new = (t_links *)malloc(sizeof(*new));
	new->room = r;
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void	pop_last_links(t_links **list)
{
	t_links *tmp;
	t_links *prev;

	tmp = *list;
	if (tmp == NULL)
		return ;
	else if (tmp->next == NULL)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}

static int	ft_full_road(t_in *p, t_rooms *r, int count)
{
	t_links *links;

	if (r == p->end_room)
	{
		add_link_lst(&p->way, r);
		return (1);
	}
	if (r->free == 0 || count > p->gc)
		return (0);
	if (r != p->start_room)
		add_link_lst(&p->way, r);
	links = r->link;
	r->free = 0;
	while (links != NULL)
	{
		if (ft_full_road(p, links->room, count + 1) == 1)
			return (1);
		links = links->next;
	}
	pop_last_links(&p->way);
	return (0);
}

void		ft_find_road(t_in *p, t_rooms *r)
{
	uintmax_t	ant;

	ant = 0;
	ft_printf("\n");
	while (p->gc++ < (int)p->room_nbr)
	{
		if (ft_full_road(p, r, 0) == 1)
			break ;
		ft_unvisit(r);
		free(p->way);
		p->way = NULL;
	}
	if (p->way != NULL)
		ft_print_send_ants(p, &ant);
	else
		ft_errors("wrong way.");
}
