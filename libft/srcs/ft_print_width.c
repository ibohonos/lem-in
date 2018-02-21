/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:23:42 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/08 19:44:47 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_part_two_width(t_struct *p, int all)
{
	int i;

	if (p->width != -1 && p->zero != -1 && p->precision == -1)
	{
		i = p->width - all;
		if (i < 0)
			p->ret_len += all - p->width;
		while (i-- > 0)
			ft_putchar('0');
	}
	else if (p->width != -1 && p->zero == -1)
	{
		i = p->width - all;
		if (i < 0)
			p->ret_len += all - p->width;
		while (i-- > 0)
			ft_putchar(' ');
	}
}

static void	ft_part_three_width(t_struct *p, int all)
{
	int i;

	if (p->width != -1 && p->zero == -1 && p->precision != -1 && p->width < all)
		if (p->width < all)
			p->ret_len -= p->width;
	if (p->width != -1 && p->zero == -1 && p->precision != -1)
	{
		if (p->space != -1)
			i = p->width - p->precision - 1;
		else
			i = p->width - p->precision;
		if (i < 0)
			p->ret_len += all - p->width;
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
		ft_part_two_width(p, all);
}

void		ft_print_width(t_struct *p, int all)
{
	int i;

	if (p->width != -1 && p->zero == -1 && p->precision < all
		&& p->precision > 0)
	{
		if (p->space != -1)
			i = p->width - all - 1;
		else
			i = p->width - all;
		if (i < 0 && p->width > p->precision)
			p->ret_len += all - p->width;
		else if (i < 0)
			p->ret_len--;
		while (i-- > 0)
			ft_putchar(' ');
		p->ret_len += p->precision - all;
	}
	else
		ft_part_three_width(p, all);
}
