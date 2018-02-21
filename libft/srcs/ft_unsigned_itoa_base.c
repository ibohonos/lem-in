/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:53:08 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/02 20:45:26 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_numb(uintmax_t i, int base)
{
	int		j;

	j = 0;
	while (i > 0)
	{
		i /= base;
		j++;
	}
	return (j);
}

static char	*ft_set_arr(char *a, uintmax_t nb, int base)
{
	int i;

	i = ft_count_numb(nb, base);
	a[i--] = '\0';
	while (nb > 0)
	{
		if (nb % base > 9)
			a[i--] = nb % base - 10 + 'a';
		else
			a[i--] = nb % base + '0';
		nb /= base;
	}
	return (a);
}

char		*ft_unsigned_itoa_base(uintmax_t n, int base)
{
	char		*a;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(a = (char*)malloc(sizeof(char) * ft_count_numb(n, base) + 1)))
		return (NULL);
	return (ft_set_arr(a, n, base));
}
