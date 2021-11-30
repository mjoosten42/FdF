/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:22 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/30 13:02:59 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale_map(t_vector **map, float scale)
{
	t_vector	**scale_matrix;

	scale_matrix = ft_matrix_scale_new(scale);
	while (*map)
		ft_vectormultiply(*map++, scale_matrix);
	ft_free_array((void **)scale_matrix);
}

void	ft_center_map(t_vector **map)
{
	t_vector	**scale_matrix;
	t_vector	*display_center;
	t_vector	*max;
	t_vector	*min;

	max = ft_get_map_max(map);
	min = ft_get_map_min(map);
	ft_vectoradd(max, min);
	scale_matrix = ft_matrix_scale_new(0.5f);
	ft_vectormultiply(max, scale_matrix);
	display_center = ft_vectornew(DISPLAY_X / 2, DISPLAY_Y / 2, 0);
	ft_vectorsubtract(display_center, max);
	while (*map)
		ft_vectoradd(*map++, display_center);
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
