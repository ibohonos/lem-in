/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_start_room.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 01:40:33 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/12 01:40:38 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    ft_parse_start_room(char *line, t_in *p, t_rooms *r)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[0] == NULL || arr[1] == NULL || arr[2] == NULL || arr[3] != NULL)
		ft_errors("ERROR");
	if (ft_strchr(arr[0], '-') != NULL)
		ft_errors("ERROR");
    while (r->name != NULL)
    {
        if (ft_strcmp(arr[0], r->name) == 0)
            ft_errors("ERROR");
        else if (r->x == ft_atoi(arr[1]) && r->y == ft_atoi(arr[2]))
            ft_errors("ERROR");
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
	r->start = 1;
	p->start = 2;
}
