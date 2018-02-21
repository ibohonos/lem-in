/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:06:48 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/21 21:16:20 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_links(char *line, t_in *p)
{
	char	**arr;

	p->end_l = 1;
	arr = ft_strsplit(line, '-');
	if (arr[0] == NULL || arr[2] != NULL)
		ft_errors("ERROR");
	p->rooms = (char **)malloc(sizeof(char *) * p->noa + 1);
}
