/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:51:53 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/13 19:05:07 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_find_command(char *line, t_in *p)
{
	if (ft_strcmp(line, "##start") == 0 && p->start == 0)
		p->start = 1;
	else if (ft_strcmp(line, "##end") == 0 && p->end == 0)
		p->end = 1;
	else if (ft_strcmp(line, "##start") == 0 && p->start > 0)
		ft_errors("duble start command");
	else if (ft_strcmp(line, "##end") == 0 && p->end > 0)
		ft_errors("duble end command");
}
