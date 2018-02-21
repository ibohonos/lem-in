/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 23:23:55 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 08:55:46 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find(char *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i] != '\0' && ft_find_types(s[i], -1) != 0
		&& ft_find_types(s[i], -1) != 1)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}
