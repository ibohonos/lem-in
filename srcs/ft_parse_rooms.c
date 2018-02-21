/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:27:14 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/21 21:01:36 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_rooms(char *line, t_in *p)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[0] == NULL || arr[3] != NULL)
		ft_errors("ERROR");
	if (ft_strchr(arr[0], '-') != NULL)
		ft_errors("ERROR");
	if (ft_strcmp(line, "##end") != 0)
	{
		p->end = 1;
		return ;
	}
	p->rooms = (char **)malloc(sizeof(char *) * p->noa + 1);
	// p->rooms[0] = ft_strdup(arr[0]);
	// p->rooms[1] = ft_atoi(arr[1]);
	// p->rooms[2] = ft_atoi(arr[2]);
}
