/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:31:08 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/22 17:42:50 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*line;
	t_in	p;
    t_rooms	r;
    t_rooms	*h;
//	int fd;

	line = NULL;
//	fd = open("/Users/ibohonos/Documents/mygit/lem-in/test2", O_RDONLY);
	ft_init_in(&p);
	ft_init_rooms(&r);
    h = &r;
//    while (get_next_line(fd, &line) > 0)
    while (get_next_line(0, &line) > 0)
	{
		lem_in(line, &p, &r, h);
		ft_strdel(&line);
	}
	if (p.end_l == 0)
		ft_errors("ERROR");
//	close(fd);
	return (0);
}
