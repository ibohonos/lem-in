/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:35:31 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/06 14:06:39 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_c(char c, t_struct *p)
{
	if (p->minus == -1)
		ft_print_width(p, 1);
	if (p->precision != -1)
		p->ret_len -= p->precision;
	ft_putchar(c);
	if (p->minus != -1)
		ft_print_width(p, 1);
	if (p->width == -1)
		p->ret_len++;
}
