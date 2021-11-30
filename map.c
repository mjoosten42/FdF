/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:22 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/30 11:56:40 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_scale_map(t_vector **map, float scale)
{
	t_vector	**scale_matrix;

	scale_matrix = ft_create_scale_matrix(scale);
	while (*map)
		ft_vectormultiply(*map++, scale_matrix);
	ft_free_array((void **)scale_matrix);
}

float	ft_get_scale(t_vector **map)
{
	t_vector	*max;
	int			display_smallest;
	float		diagonal;

	display_smallest = DISPLAY_X;
	if (display_smallest < DISPLAY_Y)
		display_smallest = DISPLAY_Y;
	max = ft_get_map_max(map);
	if (!max)
		return (0);
	diagonal = sqrt(max->x * max->x + max->y * max->y);
	diagonal = sqrt(max->z * max->z + diagonal * diagonal);
	return ((float)display_smallest / diagonal);
}

void	ft_center_map(t_vector **map)
{
	t_vector	**scale_matrix;
	t_vector	*display_center;
	t_vector	*max;
	t_vector	*min;

	max = ft_get_map_max(map);
	min = ft_get_map_min(map);
	printf("max: %f, min: %f\n", max->x, min->x);
	ft_vectoradd(max, min);
	scale_matrix = ft_create_scale_matrix(0.5f);
	ft_vectormultiply(max, scale_matrix);
	printf("A: x: %f, y: %f, z: %f\n", max->x, max->y, max->z);
	display_center = ft_vectornew(DISPLAY_X / 2, DISPLAY_Y / 2, 0);
	ft_vectorsubtract(max, display_center);
	while (*map)
		ft_vectoradd(*map++, max);
	ft_free_array((void **)scale_matrix);
	free(display_center);
	free(max);
	free(min);
}

void	ft_draw_map(t_window *window)
{
	t_vector	**map;

	map = window->map;
	while (*map)
	{
		mlx_pixel_put(window->mlx, window->win,
			(*map)->x, DISPLAY_Y - (*map)->y, WHITE);
		map++;
	}
}
//(*map)->height << 20