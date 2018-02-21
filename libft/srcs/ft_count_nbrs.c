/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 00:57:05 by ibohonos          #+#    #+#             */
/*   Updated: 2017/12/17 02:10:25 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_nbrs(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (++i);
}