/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:19:26 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/08 14:19:36 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_b(uintmax_t type_b, t_struct *p)
{
	p->buffer = ft_itoa_base(type_b, 2);
	if (p->sharp != -1 && p->width != -1)
		p->width -= 2;
	if (p->minus == -1 && p->sharp != -1 && p->zero == -1)
		ft_print_width(p, ft_strlen(p->buffer));
	if (p->sharp != -1)
	{
		ft_putstr("0b");
		if (p->width == -1 && p->precision == -1)
			p->ret_len += 2;
	}
	if ((p->minus == -1 && p->sharp == -1) || p->zero != -1)
		ft_print_width(p, ft_strlen(p->buffer));
	if (p->precision != -1 && p->precision != 0)
		ft_print_precision(p, ft_strlen(p->buffer));
	ft_putstr(p->buffer);
	if (p->minus != -1 && p->zero == -1)
		ft_print_width(p, ft_strlen(p->buffer));
	if (p->width == -1 && p->precision == -1)
		p->ret_len += ft_strlen(p->buffer);
	ft_strdel(&p->buffer);
}
