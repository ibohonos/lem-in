/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:06:59 by ibohonos          #+#    #+#             */
/*   Updated: 2018/03/20 17:07:43 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error_room(char **arr)
{
	if (arr[0] == NULL || arr[1] == NULL || arr[2] == NULL || arr[3] != NULL)
		ft_errors("it's not a room.");
	if (ft_strchr(arr[0], '-') != NULL || arr[0][0] == 'L' || arr[0][0] == '#')
		ft_errors("wrong name room.");
}
