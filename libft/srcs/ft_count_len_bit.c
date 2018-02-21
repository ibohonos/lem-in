/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len_bit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:22:48 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 18:23:03 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_len_bit(wchar_t wchar)
{
	int i;
	int l;

	i = -1;
	l = 0;
	if (wchar)
	{
		if (wchar <= 0x7F)
			l++;
		else if (wchar <= 0x7FF)
			l += 2;
		else if (wchar <= 0xFFFF)
			l += 3;
		else if (wchar <= 0x1FFFFF)
			l += 4;
	}
	return (l);
}
