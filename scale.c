/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:39:11 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 13:30:39 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_get_scale(t_vector **map)
{
	int		display_smallest;
	int		vector_biggest;

	display_smallest = ft_smallest(DISPLAY_X, DISPLAY_Y);
	vector_biggest = ft_biggest_vector(map);
	return ((float)display_smallest / (float)vector_biggest);
}

int	ft_biggest_vector(t_vector **map)
{
	int	x_max;
	int	y_max;
	int	y_min;
	int	z_max;

	x_max = (*map)->x;
	y_max = (*map)->y;
	y_min = (*map)->y;
	z_max = (*map)->z;
	while (*map)
	{
		if ((*map)->x > x_max)
			x_max = (*map)->x;
		if ((*map)->y > y_max)
			y_max = (*map)->y;
		if ((*map)->y < y_min)
			y_min = (*map)->y;
		if ((*map)->z > z_max)
			z_max = (*map)->z;
		map++;
	}
	return (ft_biggest(ft_biggest(x_max, y_max - y_min), z_max));
}

int	ft_biggest(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_smallest(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
