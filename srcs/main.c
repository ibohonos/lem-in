/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:31:08 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/21 21:16:33 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*line;
	t_in	p;

	line = NULL;
	ft_init_in(&p);
	while (get_next_line(0, &line) > 0)
	{
		lem_in(line, &p);
		ft_strdel(&line);
	}
	if (p.end_l == 0)
		ft_errors("ERROR");
	return (0);
}
