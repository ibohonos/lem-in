/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 00:01:06 by ibohonos          #+#    #+#             */
/*   Updated: 2017/12/30 22:03:01 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_flags(char *str, int i, t_struct *p)
{
	while (ft_find_types(str[i], -1) == 1)
	{
		if (str[i] == ' ' && p->plus == -1)
			p->space = 1;
		if (str[i] == '+')
		{
			p->plus = 1;
			p->space = -1;
		}
		if (str[i] == '-')
		{
			p->minus = 1;
			p->zero = -1;
		}
		if (str[i] == '#')
			p->sharp = 1;
		if (str[i] == '0' && p->precision == -1 && p->minus == -1)
			p->zero = 1;
		i++;
	}
	return (i);
}
