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

// void	ft_free_r(t_rooms *r)
// {
// 	while (r != NULL)
// 	{
// 		ft_strdel(&r->name);
// 		while (r->link != NULL)
// 		{
// 			r->link->room = NULL;
// 			r->link = r->link->next;
// 		}
// 		free(r->link);
// 		r->link = NULL;
// 		r = r->next;
// 	}
// 	free(r);
// 	r = NULL;
// }

// static t_rooms	*ft_full_road(t_rooms *end, t_rooms *r)
// {
// 	t_rooms	*queue;
// 	t_rooms	*l;

// 	// r = p->start_room;			// починаючи з вузла-джерела
// 	r->free = 0;
// 	queue = r;
// 	l = r;
// 	while (queue)		// поки черга не порожня
// 	{
// 		if (queue == end)
// 		{
// 			queue->next = NULL;
// 			return (queue);			// перевірити, чи не є поточний вузол цільовим
// 		}
// 		while (queue->link)		// всі наступники поточного вузла, ...
// 		{
// 			if (queue->link->room->free)	// ... які ще не були відвідані ...
// 			{
// 				l = l->next;
// 				ft_printf("room = %s\n", queue->link->room->name);
// 				queue->link->room->free = 0;	// ... позначити як відвідані
// 				queue = queue->link->room;		// ... додати в кінець черги...
// 				l = queue;
// 				// queue.push(child);
// 			}
// 			else
// 			{
// 				ft_printf("breack room = %s\n", queue->link->room->name);
// 				break ;
// 			}
// 		}
// 		queue = queue->next;
// 	}
// 	ft_free_r(l);
// 	return (NULL);					// цільовий вузол недосяжний
// }

// void			ft_find_road(t_in *p, t_rooms *r)
// {
// //	int		i;
// 	t_rooms	*l;

// 	ft_printf("\n");
// 	r = NULL;
// 	l = ft_full_road(p->end_room, p->start_room);
// 	// p = NULL;
// 	// r = NULL;
// 	// i = 0;
// 	// while (r != NULL)
// 	// {
// 	// 	ft_printf("name = %s\n", r->name);
// 	// 	while (r->link != NULL)
// 	// 	{
// 	// 		ft_printf("link name = %s\n", r->link->room->name);
// 	// 		r->link = r->link->next;
// 	// 	}
// 	// 	r = r->next;
// 	// 	// i++;
// 	// }
// 	// ft_printf("\n");
// 	// while (l)
// 	// {
// 	// 	while (l->link)
// 	// 	{
// 	// 		if (!l->link->room->free && l->link->room != p->end_room)
// 	// 		{
// 	// 			ft_printf("name = %s\n", l->link->room->name);
// 	// 			l = l->link->room;
// 	// 		}
// 	// 		else
// 	// 			break ;
// 	// 		// ft_printf("name 3 = %s\n", r->link->room->name);
// 	// 		l->link = l->link->next;
// 	// 	}
// 	// 	// ft_printf("name4 = %s\n", r->name);
// 	// 	l = l->next;
// 	// }
// //	ft_printf("i = %d\n", i);
// }

//static int	ft_full_road(t_rooms *end, t_rooms *r, t_rooms *l)
//{
//
//}
//
//void		ft_find_road(t_in *p, t_rooms *r)
//{
//	t_rooms *closed;
//	t_rooms *open;
//	t_rooms *path;
//
//	closed = NULL;
//	path = NULL;
//	open = p->start_room;
//	while (open)
//	{
//
//	}
//}

void	ft_unvisit(t_rooms *r)
{
	while (r)
	{
		r->free = 1;
		r = r->next;
	}
}

void add_link_lst(t_links **list, t_rooms *r)
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
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void pop_last_links(t_links **list)
{
	t_links *tmp;
	t_links *prev;

	tmp = *list;
	if (tmp == NULL)
		return;
	else if(tmp->next == NULL)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		while(tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}

static int ft_full_road(t_in *p, t_rooms *r, int count)
{
	t_links *links;

	if (r == p->end_room)
	{
		add_link_lst(&p->way, r);
		return (1);
	}
	if (r->free == 0 || count > p->gc)
		return (0);
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
	return(0);
}

void	ft_len_way(t_in *p, t_links *way)
{
	while (way)
	{
		p->len_way++;
		way = way->next;
	}
}

int		ft_send_ants(t_in *p, int k)
{
	t_links	*way;
	// int		i;
	// int		step;

	// i = 0;
	// step = 0;
	// while (i < p->noa)
	// {
	// 	way = p->way;
	// 	while (way)
	// 	{
	// 		ft_printf("L%d-%s ", i, way->room->name);
	// 		way = way->next;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }

	int i;
	int q;

	q = 0;
	way = p->way;
	ft_len_way(p, way);
	while (way)
	{
		i = -1;
		while (++i < p->len_way)
		{
			// if (way->an_w[i] && way->way[i])
			// {
				q++;
				if (k == 0)
				{
					ft_printf("L%d-%s", i + 1, way->room->name);
					k++;
				}
				else
					ft_printf(" L%d-%s", i + 1, way->room->name);
			// }
		}
		way = way->next;
	}
	return (q != 0 ? ft_printf("\n") : 0);
}

void ft_find_road(t_in *p, t_rooms *r)
{
	ft_printf("\n");
	while (p->gc < p->room_nbr)
	{
		if (ft_full_road(p, r, 0) == 1)
			break;
		ft_unvisit(r);
		free(p->way);
		p->way = NULL;
		p->gc++;
	}
	if (p->way != NULL)
	{
		// while (42)
		// {
			if (ft_send_ants(p, 0) == 0)
				;
				// break ;
		// }
	}
	else
		ft_errors("wrong way.");
}
