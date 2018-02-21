/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:58:40 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 17:58:53 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_len_bits(wchar_t *wchar)
{
	int i;
	int l;

	i = -1;
	l = 0;
	while (wchar[++i])
	{
		if (wchar[i] <= 0x7F)
			l++;
		else if (wchar[i] <= 0x7FF)
			l += 2;
		else if (wchar[i] <= 0xFFFF)
			l += 3;
		else if (wchar[i] <= 0x1FFFFF)
			l += 4;
	}
	return (l);
}
