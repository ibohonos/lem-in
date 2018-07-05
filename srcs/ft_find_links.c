/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:26:25 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/18 18:31:21 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_set_link_room(t_rooms *r, t_rooms *s)
{
	while (r->link != NULL)
		r->link = r->link->next;
	r->link = (t_links *)malloc(sizeof(t_links));
	r->link->room = s;
	r->link->next = NULL;
	while (s->link != NULL)
		s->link = s->link->next;
	s->link = (t_links *)malloc(sizeof(t_links));
	s->link->room = r;
	s->link->next = NULL;
}

static int	ft_check_links(t_rooms *r,  t_rooms *s)
{
	while (r->link != NULL)
	{
		if (r->link->room == s)
			return (1);
		r->link = r->link->next;
	}
	while (s->link != NULL)
	{
		if (s->link->room == r)
			return (1);
		s->link = s->link->next;
	}
	return (0);
}

void		ft_find_links(char *s1, char *s2, t_rooms *r)
{
	t_rooms	*s;

	s = r;
	while (r != NULL)
	{
		if (ft_strcmp(s1, r->name) != 0)
			r = r->next;
		else
			break ;
	}
	while (s != NULL)
	{
		if (ft_strcmp(s2, s->name) != 0)
			s = s->next;
		else
			break ;
	}
	if (r == NULL || s == NULL)
		ft_errors("bad link name.");
	if (ft_check_links(r, s))
		return ;
	ft_set_link_room(r, s);
}
