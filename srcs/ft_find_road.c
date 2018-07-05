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

static int	ft_full_road(t_rooms *end, t_rooms *r, t_rooms *l)
{
	t_rooms *queue;

	// r = p->start_room;			// починаючи з вузла-джерела
	r->free = 0;
	queue = r;
	l = r;
	while (queue)		// поки черга не порожня
	{
		if (queue == end)
			return (1);			// перевірити, чи не є поточний вузол цільовим
		while (queue->link)		// всі наступники поточного вузла, ...
		{
			if (queue->link->room->free)	// ... які ще не були відвідані ...
			{
				l = l->next;
				ft_printf("room = %s\n", queue->link->room->name);
				queue->link->room->free = 0;	// ... позначити як відвідані
				queue = queue->link->room;		// ... додати в кінець черги...
				l = queue;
				// queue.push(child);
			}
			else
			{
				ft_printf("breack room = %s\n", queue->link->room->name);
				break ;
			}
		}
		queue = queue->next;
	}
	return (0);					// цільовий вузол недосяжний
}

void		ft_find_road(t_in *p, t_rooms *r)
{
	int		i;
	t_rooms	l;

	ft_printf("\n");
	i = ft_full_road(p->end_room, p->start_room, &l);
	// p = NULL;
	// r = NULL;
	// i = 0;
	// while (r != NULL)
	// {
	// 	ft_printf("name = %s\n", r->name);
	// 	while (r->link != NULL)
	// 	{
	// 		ft_printf("link name = %s\n", r->link->room->name);
	// 		r->link = r->link->next;
	// 	}
	// 	r = r->next;
	// 	// i++;
	// }
	ft_printf("\n");
	while (l)
	{
		while (l.link)
		{
			if (!l.link->room->free && l.link->room != p->end_room)
			{
				ft_printf("name = %s\n", l.link->room->name);
				l = &(l)->link->room;
			}
			else
				break ;
			// ft_printf("name 3 = %s\n", r->link->room->name);
			l->link = l->link->next;
		}
		// ft_printf("name4 = %s\n", r->name);
		l = l->next;
	}
	ft_printf("i = %d\n", i);
}
