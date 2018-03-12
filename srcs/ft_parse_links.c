/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:06:48 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/12 19:42:30 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_links(char *line, t_in *p, t_rooms *r)
{
	char	**arr;

	if (ft_strchr(line, '-') == NULL)
	{
		ft_parse_rooms(line, p, r);
		return ;
	}
	arr = ft_strsplit(line, '-');
	if (arr[0] == NULL || arr[1] == NULL || arr[2] != NULL)
		ft_errors("ERROR");
	ft_find_links(arr[0], arr[1], r);
	p->end_l = 1;
}
