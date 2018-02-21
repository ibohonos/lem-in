/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:19:26 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 18:05:07 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_p(long long type_p, t_struct *p)
{
	p->buffer = ft_itoa_base(type_p, 16);
	if (p->minus == -1 && p->zero == -1)
		ft_print_width(p, ft_strlen(p->buffer) + 2);
	ft_putstr("0x");
	if (p->minus == -1 && p->zero != -1)
		ft_print_width(p, ft_strlen(p->buffer) + 2);
	if (p->width == -1 && p->precision == -1)
		p->ret_len += 2;
	if (p->precision != -1)
		ft_print_precision(p, ft_strlen(p->buffer));
	ft_putstr(p->buffer);
	if (p->minus != -1)
		ft_print_width(p, ft_strlen(p->buffer) + 2);
	if (p->width == -1 && p->precision == -1)
		p->ret_len += ft_strlen(p->buffer);
	ft_strdel(&p->buffer);
}
