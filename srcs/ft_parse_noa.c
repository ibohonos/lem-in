/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_noa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:02:43 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/13 18:44:48 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_noa(char *line, t_in *p)
{
	p->noa = ft_atoi(line);
	if (p->noa <= 0)
		ft_errors("wrong number ants.");
	else if (line[ft_count_nbrs(p->noa)] != '\0')
		ft_errors("ants only numbers.");
}
