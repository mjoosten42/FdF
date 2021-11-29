/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:13:34 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 15:13:35 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_get_x_max(t_vector **map)
{
	float	x_max;

	x_max = (*map)->x;
	while (*map)
	{
		if ((*map)->x > x_max)
			x_max = (*map)->x;
		map++;
	}
	return (x_max);
}

float	ft_get_x_min(t_vector **map)
{
	float	x_min;

	x_min = (*map)->x;
	while (*map)
	{
		if ((*map)->x < x_min)
			x_min = (*map)->x;
		map++;
	}
	return (x_min);
}
