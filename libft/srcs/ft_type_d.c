/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 04:53:28 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 17:48:28 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_d_help4(t_struct *p, int minus)
{
	if (p->minus != -1)
	{
		if (p->plus != -1 || minus == 1)
			ft_print_width(p, ft_strlen(p->buffer) + 1);
		else
			ft_print_width(p, ft_strlen(p->buffer));
	}
	if (p->width == -1 && p->precision == -1)
		p->ret_len += ft_strlen(p->buffer);
	ft_strdel(&p->buffer);
}

void	ft_type_d_help3(int type_d, t_struct *p, int minus)
{
	if (type_d < 0 && type_d != -2147483648 && p->zero == -1)
	{
		ft_putchar('-');
		type_d *= -1;
		minus = 1;
		ft_strdel(&p->buffer);
		p->buffer = ft_itoa_base(type_d, 10);
		if (p->width == -1)
			p->ret_len++;
	}
	else if (p->plus != -1 && p->zero == -1)
	{
		ft_putchar('+');
		if (p->width == -1)
			p->ret_len++;
	}
	if (p->precision != -1)
		ft_print_precision(p, ft_strlen(p->buffer));
	if ((p->precision == 0 && type_d != 0) || (type_d == 0 && p->plus != -1) ||
		p->precision != 0)
		ft_putstr(p->buffer);
	else if (p->precision == 0 && type_d == 0)
		p->ret_len--;
	ft_type_d_help4(p, minus);
}

void	ft_type_d_help2(int type_d, t_struct *p, int minus)
{
	if ((minus == 1 || p->plus != -1 || type_d < 0)
		&& p->precision != -1 && p->width != -1)
	{
		if (p->width > p->precision)
			p->width--;
		if ((minus == 1 || type_d < 0) && p->width < p->precision
			&& p->precision < (int)ft_strlen(p->buffer))
			p->ret_len++;
	}
	if (p->precision > p->width && p->width > 0)
		p->ret_len++;
	if (p->minus == -1)
	{
		if (p->plus != -1 || minus == 1)
			ft_print_width(p, ft_strlen(p->buffer) + 1);
		else
			ft_print_width(p, ft_strlen(p->buffer));
	}
	ft_type_d_help3(type_d, p, minus);
}

void	ft_type_d_help(int type_d, t_struct *p)
{
	int minus;

	minus = 0;
	if (type_d < 0 && type_d != -2147483648 && p->zero != -1)
	{
		ft_putchar('-');
		type_d *= -1;
		minus = 1;
		ft_strdel(&p->buffer);
		p->buffer = ft_itoa_base(type_d, 10);
		if (p->width == -1)
			p->ret_len++;
	}
	else if (p->plus != -1 && p->zero != -1)
	{
		ft_putchar('+');
		if (p->width == -1)
			p->ret_len++;
	}
	ft_type_d_help2(type_d, p, minus);
}

void	ft_type_d(int type_d, t_struct *p)
{
	if (p->precision != -1)
		p->zero = -1;
	p->buffer = ft_itoa_base(type_d, 10);
	if (p->space != -1 && type_d >= 0)
	{
		ft_putchar(' ');
		if (p->width == -1)
			p->ret_len++;
	}
	if (p->space != -1 && p->width != -1 && p->precision == -1)
		p->width--;
	if (type_d < 0 && p->precision < (int)ft_strlen(p->buffer)
		&& p->precision != -1 && p->width != -1)
	{
		p->width++;
		p->ret_len++;
	}
	ft_type_d_help(type_d, p);
}
