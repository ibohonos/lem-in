/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:49:17 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 20:10:46 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_types(char format, int i)
{
	while (FLAGS[++i] != '\0')
		if (FLAGS[i] == format)
			return (1);
	if (format > '0' && format <= '9')
		return (2);
	if (format == '.')
		return (3);
	i = -1;
	while (MODIFICATORS[++i] != '\0')
		if (MODIFICATORS[i] == format)
			return (4);
	i = -1;
	while (SPEC[++i] != '\0')
		if (SPEC[i] == format)
			return (5);
	i = -1;
	while (BONUS_SPEC[++i] != '\0')
		if (BONUS_SPEC[i] == format)
			return (5);
	return (0);
}
