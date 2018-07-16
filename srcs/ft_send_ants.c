/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:29:53 by ibohonos          #+#    #+#             */
/*   Updated: 2018/04/17 12:56:24 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links	*ft_swap_way(t_links *way)
{
	t_links	*tmp[3];

	tmp[0] = (t_links *)malloc(sizeof(t_links));
	tmp[1] = way;
	tmp[2] = tmp[0];
	while (way)
		if (way->next == NULL)
		{
			tmp[2]->room = way->room;
			tmp[2]->next = NULL;
			free(way);
			way = NULL;
		}
		else if (way->next->next == NULL)
		{
			tmp[2]->room = way->next->room;
			tmp[2]->next = (t_links *)malloc(sizeof(t_links));
			tmp[2] = tmp[2]->next;
			free(way->next);
			way->next = NULL;
			way = tmp[1];
		}
		else
			way = way->next;
	return (tmp[0]);
}

int		ft_send_ants(t_in *p)
{
	t_links	*way;
	int		res;

	way = p->way;
	res = 0;
	while (way)
	{
		if (way->next && way->next->room->ant)
		{
			if (res != 0)
				ft_printf(" ");
			ft_printf("L%ju-%s", way->next->room->ant, way->room->name);
			way->room->ant = way->next->room->ant;
			way->next->room->ant = 0;
			res = 1;
		}
		way = way->next;
	}
	return (res);
}

int		ft_send_new_ants(t_in *p, uintmax_t *ant, int res)
{
	if (*ant >= p->noa)
		return (0);
	if (res)
		ft_putchar(' ');
	ft_printf("L%ju-%s", ++(*ant), p->start_room->name);
	p->start_room->ant = *ant;
	return (1);
}

void	ft_print_send_ants(t_in *p, uintmax_t *ant)
{
	int			res;

	p->start_room = p->way->room;
	p->way = ft_swap_way(p->way);
	while (42)
	{
		res = 0;
		res += ft_send_ants(p);
		res += ft_send_new_ants(p, ant, res);
		if (res == 0)
			break ;
		ft_printf("\n");
	}
}
