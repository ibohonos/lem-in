/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:31:08 by ibohonos          #+#    #+#             */
/*   Updated: 2018/04/15 16:11:57 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_count_rooms(t_in *p, t_rooms *r)
{
	t_rooms	*tmp;

	tmp = r;
	while (tmp)
	{
		p->room_nbr++;
		tmp = tmp->next;
	}
	free(tmp);
}

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
		ft_printf("%s\n", line);
		lem_in(line, &p, &r);
		ft_strdel(&line);
	}
	if (p.end_l == 0)
		ft_errors("no links.");
	ft_count_rooms(&p, &r);
	ft_find_road(&p, &r);
	close(fd);
	ft_free_all(&p, &r);
	// system("leaks lem-in");
	return (0);
}
