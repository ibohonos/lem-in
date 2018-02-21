/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:53:08 by ibohonos          #+#    #+#             */
/*   Updated: 2017/12/30 20:49:23 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_numb(uintmax_t i, int minus, int base)
{
	int		j;

	j = 0;
	if (minus == 1 && base == 10)
		j++;
	while (i > 0)
	{
		i /= base;
		j++;
	}
	return (j);
}

static char	*ft_set_arr(char *a, uintmax_t nb, int base, int minus)
{
	int i;

	i = ft_count_numb(nb, minus, base);
	a[i--] = '\0';
	while (nb > 0)
	{
		if (nb % base > 9)
			a[i--] = nb % base - 10 + 'a';
		else
			a[i--] = nb % base + '0';
		nb /= base;
	}
	if (minus == 1 && base == 10)
		a[i] = '-';
	return (a);
}

char		*ft_itoa_base(intmax_t n, int base)
{
	int			minus;
	char		*a;
	uintmax_t	nb;

	minus = 0;
	if (n < 0)
		minus = 1;
	if (minus == 1)
		nb = n * -1;
	else
		nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(a = (char*)malloc(sizeof(char) * ft_count_numb(nb, minus, base) + 1)))
		return (NULL);
	return (ft_set_arr(a, nb, base, minus));
}
