/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:27:14 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/20 19:11:56 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_rooms(char *line, t_rooms *r)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	ft_error_room(arr);
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
	r->name = ft_strdup(arr[0]);
	r->x = ft_atoi(arr[1]);
	r->y = ft_atoi(arr[2]);
	ft_free_arr(&arr);
}
