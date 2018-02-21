/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_end_room.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:03:46 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/21 21:17:08 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_end_room(char *line, t_in *p)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[0] == NULL || arr[3] != NULL)
		ft_errors("ERROR");
	if (ft_strchr(arr[0], '-') != NULL)
		ft_errors("ERROR");
	p->end_r = 1;
}
