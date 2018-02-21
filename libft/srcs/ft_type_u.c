/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 22:09:04 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 18:12:02 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_u_help(t_struct *p)
{
	if (p->precision == 0)
		p->ret_len -= ft_strlen(p->buffer);
	if (p->precision != 0)
		ft_putstr(p->buffer);
	if (p->minus != -1)
		ft_print_width(p, ft_strlen(p->buffer));
	if (p->width == -1 && p->precision == -1)
		p->ret_len += ft_strlen(p->buffer);
	ft_strdel(&p->buffer);
}

void	ft_type_u(unsigned int type_u, t_struct *p)
{
	int i;

	p->buffer = ft_unsigned_itoa_base(type_u, 10);
	if (p->plus != -1 && p->precision != -1 && p->width != -1)
	{
		if (p->width > p->precision)
			p->width--;
		if (p->width < p->precision && p->precision < (int)ft_strlen(p->buffer))
			p->ret_len++;
	}
	if (p->precision > p->width && p->width > 0)
		p->ret_len++;
	if (p->minus == -1)
		ft_print_width(p, ft_strlen(p->buffer));
	if (p->precision != -1)
	{
		i = p->precision - ft_strlen(p->buffer);
		if (i < 0)
			p->ret_len += ft_strlen(p->buffer)
				- p->precision;
		while (i-- > 0)
			ft_putchar('0');
	}
	ft_type_u_help(p);
}
