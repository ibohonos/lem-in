/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:16:27 by ibohonos          #+#    #+#             */
/*   Updated: 2017/12/30 21:28:18 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_width(char *s, int i, t_struct *p)
{
	if (s[i] > '0' && s[i] <= '9')
	{
		p->width = ft_atoi(s + i);
		while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
			i++;
	}
	if (p->width > 0)
		p->ret_len += p->width;
	return (i);
}
