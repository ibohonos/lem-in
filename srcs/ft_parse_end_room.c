/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_end_room.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:03:46 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/22 18:41:58 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_end_room(char *line, t_in *p, t_rooms *r)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[0] == NULL || arr[1] == NULL || arr[2] == NULL || arr[3] != NULL)
		ft_errors("ERROR");
	if (ft_strchr(arr[0], '-') != NULL)
		ft_errors("ERROR");
	p->end_r = 1;
	r->name = arr[0];
	r->x = ft_atoi(arr[1]);
	r->y = ft_atoi(arr[2]);
	r->next = NULL;
}
