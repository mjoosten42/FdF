/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:39:11 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 14:48:27 by mjoosten         ###   ########.fr       */
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

float	ft_get_z_max(t_vector **map)
{
	float	z_max;

	z_max = (*map)->z;
	while (*map)
	{
		if ((*map)->z > z_max)
			z_max = (*map)->z;
		map++;
	}
	return (z_max);
}