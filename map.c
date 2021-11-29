/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:22 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 16:05:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_scale_map(t_vector **map, float scale)
{
	t_vector	**scale_matrix;
	t_vector	**start;
	t_vector	*move;

	start = map;
	move = ft_base_map(map);
	ft_matrix_add(map, move);
	scale_matrix = ft_create_scale_matrix(scale);
	while (*map)
		ft_matrix_multiply(*map++, scale_matrix);
	ft_matrix_multiply(move, scale_matrix);
	ft_free_array((void **)scale_matrix);
	ft_vector_invert(move);
	ft_matrix_add(start, move);
	free(move);
}

void	ft_center_map(t_vector **map)
{
	t_vector	*add_matrix;
	t_vector	**start;
	float		x_max;
	float		y_max;

	start = map;
	x_max = (*map)->x;
	y_max = (*map)->y;
	while (*map)
	{
		if ((*map)->x > x_max)
			x_max = (*map)->x;
		if ((*map)->y > y_max)
			y_max = (*map)->y;
		map++;
	}
	add_matrix = ft_create_move_matrix(
			(DISPLAY_X - x_max) / 2,
			(DISPLAY_Y - y_max) / 2,
			0);
	ft_matrix_add(start, add_matrix);
	free(add_matrix);
}

float	ft_get_scale(t_vector **map)
{
	int		display_smallest;
	float	diagonal;
	float	x_max;
	float	y_max;
	float	z_max;

	display_smallest = DISPLAY_X;
	if (display_smallest < DISPLAY_Y)
		display_smallest = DISPLAY_Y;
	x_max = ft_get_x_max(map);
	y_max = ft_get_y_max(map);
	z_max = ft_get_z_max(map);
	diagonal = sqrt(x_max * x_max + y_max * y_max);
	diagonal = sqrt(z_max * z_max + diagonal * diagonal);
	return ((float)display_smallest / diagonal);
}

t_vector	*ft_base_map(t_vector **map)
{
	t_vector	*move;
	float		x_min;
	float		y_min;
	float		z_min;

	x_min = ft_get_x_min(map);
	y_min = ft_get_y_min(map);
	z_min = ft_get_z_min(map);
	if (y_min >= 0)
		move = ft_create_move_matrix(-x_min, -y_min, -z_min);
	else
		move = ft_create_move_matrix(-x_min, y_min, -z_min);
	return (move);
}
