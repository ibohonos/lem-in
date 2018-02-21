/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:25:48 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 18:07:43 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_s_help(char *s, t_struct *p)
{
	if (p->precision != -1 && p->width == -1)
		p->ret_len = (p->ret_len - p->precision) + ft_strlen(s);
	if (p->precision != -1 && p->precision < (int)ft_strlen(s))
	{
		p->buffer = ft_strsub(s, 0, p->precision);
		ft_putstr(p->buffer);
		ft_strdel(&p->buffer);
		p->ret_len -= ft_strlen(s) - p->precision;
	}
	else
		ft_putstr(s);
	if (p->minus != -1)
	{
		if (p->precision < (int)ft_strlen(s) && p->precision != -1)
			ft_print_width(p, ft_strlen(s) - p->precision);
		else
			ft_print_width(p, ft_strlen(s));
	}
	if (p->width == -1 && p->precision == -1)
		p->ret_len += ft_strlen(s);
}

void	ft_type_s(char *s, t_struct *p)
{
	int i;

	if (!s)
	{
		ft_putstr("(null)");
		p->ret_len += 6;
		return ;
	}
	if (p->minus == -1)
	{
		if (p->precision < (int)ft_strlen(s) && p->precision != -1)
			ft_print_width(p, ft_strlen(s) - p->precision);
		else
			ft_print_width(p, ft_strlen(s));
	}
	if (p->precision != -1 && p->width != -1)
	{
		i = p->precision - ft_strlen(s);
		if (i < 0)
			p->ret_len += ft_strlen(s) - p->precision;
		while (i-- > 0)
			ft_putchar(' ');
	}
	ft_type_s_help(s, p);
}
