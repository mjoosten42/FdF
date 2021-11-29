/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gety.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:14:02 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 15:14:03 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_get_y_max(t_vector **map)
{
	float	y_max;

	y_max = (*map)->y;
	while (*map)
	{
		if ((*map)->y > y_max)
			y_max = (*map)->y;
		map++;
	}
	return (y_max);
}

float	ft_get_y_min(t_vector **map)
{
	float	y_min;

	y_min = (*map)->y;
	while (*map)
	{
		if ((*map)->y < y_min)
			y_min = (*map)->y;
		map++;
	}
	return (y_min);
}
