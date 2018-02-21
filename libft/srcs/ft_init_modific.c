/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_modific.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:57:39 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 19:19:13 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_help_init_modific(char *str, int i, t_struct *p)
{
	if (ft_find(str, i, 'l') / 2 != 1 && ft_find(str, i, 'l') != 0
		&& p->spec_ll == 0 && p->spec_j == 0 && p->spec_z == 0)
	{
		p->spec_l = 1;
		i++;
	}
	if (ft_find(str, i, 'h') / 2 == 1 && ft_find(str, i, 'h') != 0
		&& p->spec_ll == 0 && p->spec_l == 0 && p->spec_j == 0
		&& p->spec_z == 0)
	{
		p->spec_h = 0;
		p->spec_hh = 1;
		i += 2;
	}
	if (ft_find(str, i, 'h') / 2 != 1 && ft_find(str, i, 'h') != 0
		&& p->spec_hh == 0 && p->spec_ll == 0 && p->spec_l == 0
		&& p->spec_j == 0 && p->spec_z == 0)
	{
		p->spec_h = 1;
		i++;
	}
	return (i);
}

int	ft_init_modific(char *str, int i, t_struct *p)
{
	while (ft_find_types(str[i], -1) == 4)
	{
		if (ft_strstr(str, "z"))
		{
			p->spec_z = 1;
			i++;
		}
		if (ft_strstr(str, "j") && p->spec_z == 0)
		{
			p->spec_j = 1;
			i++;
		}
		if (ft_find(str, i, 'l') / 2 == 1 && ft_find(str, i, 'l') != 0
			&& p->spec_j == 0 && p->spec_z == 0)
		{
			p->spec_l = 0;
			p->spec_ll = 1;
			i += 2;
		}
		i = ft_help_init_modific(str, i, p);
		if (ft_find_types(str[i], -1) == 4)
			i++;
	}
	return (i);
}
