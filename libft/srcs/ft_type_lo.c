/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_lo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:39:41 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 18:15:41 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_lo_help2(unsigned long type_lo, t_struct *p)
{
	if ((p->sharp != -1 && p->zero == -1 && type_lo != 0) ||
		(p->sharp != -1 && p->precision == 0 && type_lo == 0))
	{
		ft_putstr("0");
		if (p->width == -1 && p->precision == -1)
			p->ret_len++;
	}
	if ((p->precision == 0 && type_lo != 0) || (type_lo == 0 && p->plus != -1)
		|| p->precision != 0)
		ft_putstr(p->buffer);
	else if (p->precision == 0 && type_lo == 0)
		p->ret_len--;
	if (p->minus != -1)
	{
		if (p->sharp != -1 && p->zero == -1)
			ft_print_width(p, ft_strlen(p->buffer) + 1);
		else if (p->sharp != -1 && p->zero != -1)
			ft_print_width(p, ft_strlen(p->buffer) + 2);
		else
			ft_print_width(p, ft_strlen(p->buffer));
	}
	if (p->width == -1 && p->precision == -1)
		p->ret_len += ft_strlen(p->buffer);
	ft_strdel(&p->buffer);
}

void	ft_type_lo_help(unsigned long type_lo, t_struct *p)
{
	int i;

	if (p->space != -1 && p->width == -1)
	{
		ft_putchar(' ');
		p->ret_len++;
	}
	if (p->precision != -1)
	{
		i = p->precision - ft_strlen(p->buffer);
		if (i < 0)
			p->ret_len += ft_strlen(p->buffer) - p->precision;
		while (i-- > 0)
			ft_putchar('0');
	}
	if (p->sharp != -1 && p->zero != -1)
	{
		ft_putstr("0x");
		if (p->width == -1 && p->precision == -1)
			p->ret_len += 2;
	}
	ft_type_lo_help2(type_lo, p);
}

void	ft_type_lo(unsigned long type_lo, t_struct *p)
{
	p->buffer = ft_unsigned_itoa_base(type_lo, 8);
	if (p->plus != -1 && p->precision != -1 && p->width != -1)
	{
		if (p->width > p->precision)
			p->width--;
		if (p->width < p->precision && p->precision < (int)ft_strlen(p->buffer))
			p->ret_len++;
	}
	if (p->precision > p->width && p->width > 0
		&& p->width > (int)ft_strlen(p->buffer))
		p->ret_len++;
	if (p->sharp != -1 && p->precision == 0 && p->width == -1)
		p->ret_len++;
	if (p->minus == -1)
	{
		if (p->sharp != -1 && p->zero == -1)
			ft_print_width(p, ft_strlen(p->buffer) + 1);
		else if (p->sharp != -1 && p->zero != -1)
			ft_print_width(p, ft_strlen(p->buffer) + 2);
		else
			ft_print_width(p, ft_strlen(p->buffer));
	}
	ft_type_lo_help(type_lo, p);
}
