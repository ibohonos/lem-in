/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:31:08 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/20 20:20:00 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_all(t_in *p, t_rooms *r)
{
	ft_init_in(p);
	while (r != NULL)
	{
		ft_strdel(&r->name);
		while (r->link != NULL)
		{
			r->link->room = NULL;
			r->link = r->link->next;
		}
		free(r->link);
		r->link = NULL;
		r = r->next;
	}
	free(r);
	r = NULL;
}

int	main(int argc, char **argv)
{
	char	*line;
	t_in	p;
	t_rooms	r;
	int fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	line = NULL;
	ft_init_in(&p);
	ft_init_rooms(&r);
	while (get_next_line(fd, &line) > 0)
	{
		// system("leaks lem-in");
		// exit(0);
		// while (1);
		ft_printf("%s\n", line);
		lem_in(line, &p, &r);
		free(line);
	}
	if (p.end_l == 0)
		ft_errors("no links.");
	ft_find_road(&p, &r);
	close(fd);
	ft_free_all(&p, &r);
	//system("leaks lem-in");
	return (0);
}
