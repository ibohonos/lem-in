/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:26:25 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/22 19:26:25 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_find_first(char *s1, char *s2, t_rooms *r)
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
	if (r == NULL)
		ft_errors("Bad link name");
	while (s != NULL)
	{
		if (ft_strcmp(s2, s->name) != 0)
			s = s->next;
		else
			break ;
	}
	if (s == NULL)
		ft_errors("Bad link name");
//	if (r->link == NULL)
//	{
//		r->link = (t_rooms **)malloc(sizeof(t_rooms *));
//		r->(*link) = NULL;
//	}
//	if (r->(*link) == NULL)
//		r->(*link) = r->link = (t_rooms *)malloc(sizeof(t_rooms));
}
