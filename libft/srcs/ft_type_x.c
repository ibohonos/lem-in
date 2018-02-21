/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 22:09:04 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 19:03:33 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_x_help3(unsigned int type_x, t_struct *p, int b, char *s)
{
	char	*c;

	c = ft_itoa_base(type_x, 16);
	p->buffer = c;
	if (b == 1)
		p->buffer = ft_strupper(c);
	else
		p->buffer = ft_itoa_base(type_x, 16);
	if ((p->precision == 0 && type_x != 0) || (type_x == 0 && p->plus != -1) ||
		p->precision != 0)
		ft_putstr(p->buffer);
	else if (p->precision == 0 && type_x == 0)
		p->ret_len--;
	ft_strdel(&p->buffer);
	ft_strdel(&c);
	if (p->minus != -1)
	{
		if (p->width != -1 && p->zero == -1 && p->precision != -1)
			ft_type_x_help_if_4(s, p);
		else if (p->width != -1 && p->zero == -1)
			ft_type_x_help_if_5(s, p);
	}
	if (p->width == -1 && p->precision == -1)
		p->ret_len += ft_strlen(s);
	ft_strdel(&s);
}

void	ft_type_x_help2(unsigned int type_x, t_struct *p, int b, char *s)
{
	int		i;

	if (p->minus == -1)
	{
		if (p->width != -1 && p->zero != -1 && p->precision == -1)
		{
			if (p->sharp != -1)
				i = p->width - ft_strlen(s) - 2;
			else
				i = p->width - ft_strlen(s);
			if (i < 0)
				p->ret_len += ft_strlen(s) - p->width;
			while (i-- > 0)
				ft_putchar('0');
		}
	}
	i = ft_strlen(s);
	if (p->precision != -1)
		ft_type_x_help_if_3(s, p, i);
	ft_type_x_help3(type_x, p, b, s);
}

void	ft_type_x_help(unsigned int type_x, t_struct *p, int b, char *s)
{
	if (p->minus == -1)
	{
		if (p->width != -1 && p->zero == -1 && p->precision != -1)
			ft_type_x_help_if_1(s, p);
		else if (p->width != -1 && p->zero == -1)
			ft_type_x_help_if_2(s, p);
	}
	if (p->sharp != -1 && b != 1 && type_x > 0)
	{
		ft_putstr("0x");
		if (p->width == -1 && p->precision == -1)
			p->ret_len += 2;
	}
	else if (p->sharp != -1 && b == 1 && type_x > 0)
	{
		ft_putstr("0X");
		if (p->width == -1 && p->precision == -1)
			p->ret_len += 2;
	}
	ft_type_x_help2(type_x, p, b, s);
}

void	ft_type_x(unsigned int type_x, t_struct *p, int b)
{
	char	*s;

	s = ft_itoa_base(type_x, 16);
	if (p->plus != -1 && p->precision != -1 && p->width != -1)
	{
		if (p->width > p->precision)
			p->width--;
		if (p->width < p->precision && p->precision < (int)ft_strlen(s))
			p->ret_len++;
	}
	if (p->precision > p->width && p->width > 0
		&& p->width > (int)ft_strlen(s))
		p->ret_len++;
	if ((int)ft_strlen(s) > p->width && p->width != -1
		&& p->width < p->precision)
		p->ret_len -= p->width;
	if (p->precision == (int)ft_strlen(s) && p->plus == -1 && p->precision != -1
		&& p->width != -1)
		p->ret_len--;
	ft_type_x_help(type_x, p, b, s);
}
