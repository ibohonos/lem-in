/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_help_ifs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:54:57 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 19:03:41 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_x_help_if_1(char *s, t_struct *p)
{
	int i;

	if (p->precision > (int)ft_strlen(s))
		i = p->width - p->precision;
	else if (p->precision == 0)
	{
		i = p->width;
		p->ret_len++;
	}
	else
		i = p->width - ft_strlen(s);
	if (i < 0)
		p->ret_len += ft_strlen(s) - p->width;
	while (i-- > 0)
		ft_putchar(' ');
}

void	ft_type_x_help_if_2(char *s, t_struct *p)
{
	int i;

	if (p->sharp != -1)
		i = p->width - ft_strlen(s) - 2;
	else
		i = p->width - ft_strlen(s);
	if (i < 0)
		p->ret_len += ft_strlen(s) - p->width;
	while (i-- > 0)
		ft_putchar(' ');
}

void	ft_type_x_help_if_3(char *s, t_struct *p, int i)
{
	if (p->sharp != -1)
		i = p->precision - ft_strlen(s) - 2;
	else
		i = p->precision - ft_strlen(s);
	if (i < 0 && p->width == -1)
		p->ret_len += ft_strlen(s) - p->precision;
	while (i-- > 0)
		ft_putchar('0');
}

void	ft_type_x_help_if_4(char *s, t_struct *p)
{
	int i;

	if (p->precision > (int)ft_strlen(s))
		i = p->width - p->precision;
	else
		i = p->width - ft_strlen(s);
	if (i < 0)
		p->ret_len += ft_strlen(s) - p->width;
	while (i-- > 0)
		ft_putchar(' ');
}

void	ft_type_x_help_if_5(char *s, t_struct *p)
{
	int i;

	if (p->sharp != -1)
		i = p->width - ft_strlen(s) - 2;
	else
		i = p->width - ft_strlen(s);
	if (i < 0)
		p->ret_len += ft_strlen(s) - p->width;
	while (i-- > 0)
		ft_putchar(' ');
}
