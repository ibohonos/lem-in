/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:27:14 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/12 01:39:48 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_rooms(char *line, t_in *p, t_rooms *r)
{
	char	**arr;

	if (ft_strcmp(line, "##end") == 0)
	{
		p->end = 1;
		return ;
	}
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
}
