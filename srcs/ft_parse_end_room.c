/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_end_room.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:03:46 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/18 18:54:14 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_end_room(char *line, t_in *p, t_rooms *r)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[0] == NULL || arr[1] == NULL || arr[2] == NULL || arr[3] != NULL)
		ft_errors("it's not room.");
	if (ft_strchr(arr[0], '-') != NULL || arr[0][0] == 'L' || arr[0][0] == '#')
		ft_errors("wrong name room.");
	while (r->name != NULL)
	{
		if (ft_strcmp(arr[0], r->name) == 0)
			ft_errors("duble name.");
		else if (r->x == ft_atoi(arr[1]) && r->y == ft_atoi(arr[2]))
			ft_errors("duble coords.");
		if (r->next == NULL)
		{
			r->next = (t_rooms *)malloc(sizeof(t_rooms));
			ft_init_rooms(r->next);
		}
		r = r->next;
	}
	r->name = arr[0];
	r->x = ft_atoi(arr[1]);
	r->y = ft_atoi(arr[2]);
	p->end = 2;
	p->end_room = r;
	ft_free_arr(&arr);
}
