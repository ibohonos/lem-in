/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:11:03 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/08 00:14:33 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_precision(char *s, int i, t_struct *p)
{
	i++;
	if (s[i] >= '0' && s[i] <= '9')
	{
		p->precision = ft_atoi(s + i);
		while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
			i++;
	}
	else
		p->precision = 0;
	if (p->minus == 1 && p->precision != -1)
		p->zero = -1;
	if (p->precision != -1 && p->width == -1)
		p->ret_len += p->precision;
	else if (p->precision != -1 && p->width != -1)
		p->ret_len += 0;
	if (p->precision > p->width && p->width != -1)
		p->ret_len += p->precision - p->width + 1;
	return (i);
}
