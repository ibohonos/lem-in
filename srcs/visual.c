/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:45:14 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/14 18:31:37 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init_map(t_rooms *r, t_map *m)
{
	int		i;
	int		j;

	m->x = 0;
	m->y = 0;
	while (r != NULL)
	{
		if (r->x > m->x)
			m->x = r->x;
		if (r->y > m->y)
			m->y = r->y;
		// ft_printf(MAG"[%d] - [%d]\n"RESET, r->x, r->y);
		r = r->next;
	}
	m->map = (char ***)malloc(sizeof(char **) * m->y + 1);
	i = -1;
	while (++i <= m->y)
	{
		j = -1;
		m->map[i] = (char **)malloc(sizeof(char *) * m->x + 1);
		while (++j <= m->x)
			m->map[i][j] = ft_strdup(" ");
		m->map[i][j] = NULL;
	}
	m->map[i] = NULL;
}

void	ft_print_rooms(t_rooms *r)
{
	int		i;
	int		j;
	t_map	m;

	ft_init_map(r, &m);
	while (r != NULL)
	{
		// ft_printf(CYN"[%s]\n"RESET, m.map[r->y][r->x]);
		m.map[r->y][r->x] = ft_strdup(r->name);
		// ft_printf(RED"[%s]\n"RESET, r->name);
		// ft_printf(GRN"[%s]\n"RESET, m.map[r->y][r->x]);
		r = r->next;
	}
	i = -1;
	while (++i <= m.y)
	{
		j = -1;
		while (++j <= m.x)
			ft_printf(CYN"%s"RESET, m.map[i][j]);
		ft_printf("\n");
	}
}

int		main(void)
{
	char	*line;
	t_in	p;
	t_rooms	r;

	line = NULL;
	ft_init_in(&p);
	ft_init_rooms(&r);
	while (get_next_line(0, &line) > 0 && line[0] != '\0')
	{
		// ft_printf(GRN"%s\n"RESET, line);
		lem_in(line, &p, &r);
		ft_strdel(&line);
	}
	ft_print_rooms(&r);
	return (0);
}
