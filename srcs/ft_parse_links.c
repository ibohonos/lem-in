/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:06:48 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/22 16:29:13 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_links(char *line, t_in *p, t_rooms *r, t_rooms *h)
{
	char	**arr;

	p->end_l = 1;
	arr = ft_strsplit(line, '-');
	if (arr[0] == NULL || arr[1] == NULL || arr[2] != NULL)
		ft_errors("ERROR");
	r = h;
	ft_find_first(arr[0], arr[1], r);
//	ft_find_second(arr[1], r);

}
