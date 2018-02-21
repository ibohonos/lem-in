/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_default_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 00:24:09 by ibohonos          #+#    #+#             */
/*   Updated: 2017/12/21 18:34:24 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_default_all(t_struct *p)
{
	p->sharp = -1;
	p->zero = -1;
	p->minus = -1;
	p->plus = -1;
	p->space = -1;
	p->width = -1;
	p->precision = -1;
	p->spec_h = 0;
	p->spec_hh = 0;
	p->spec_l = 0;
	p->spec_ll = 0;
	p->spec_j = 0;
	p->spec_z = 0;
	p->buffer = NULL;
}
