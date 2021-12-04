/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:22 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/04 14:24:57 by mjoosten         ###   ########.fr       */
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
	t_vector	*display_center;
	t_vector	*map_center;

	map_center = ft_mapcenter(map);
	if (!map_center)
		return ;
	printvector(map_center);
	display_center = ft_vectornew(DISPLAY_X / 2, DISPLAY_Y / 2, 0);
	if (!display_center)
		return ;
	ft_vectorsubtract(display_center, map_center);
	display_center->z = 0;
	while (*map)
		ft_vectoradd(*map++, display_center);
	free(display_center);
	free(map_center);
}

void	ft_rotate_map(t_vector **map, char c, float angle)
{
	t_vector	**rotate_matrix;

	rotate_matrix = ft_matrix_rotate_new(c, angle);
	if (!rotate_matrix)
		return ;
	while (*map)
		ft_vectormultiply(*map++, rotate_matrix);
	ft_free_array((void **)rotate_matrix);
}

void	ft_draw_map(t_window *window)
{
	t_vector	**map;
	int			i;

	map = window->map;
	i = 0;
	mlx_clear_window(window->mlx, window->win);
	while (map[i])
	{
		mlx_pixel_put(window->mlx, window->win,
			map[i]->x, DISPLAY_Y - map[i]->y, WHITE);
		if (i > window->width)
			ft_drawline(window, map[i], map[i - window->width]);
		if (i % window->width)
			ft_drawline(window, map[i], map[i - 1]);
		i++;
	}
}

void	printvector(t_vector *vector)
{
	printf("x: %f, y: %f, z: %f\n", vector->x, vector->y, vector->z);
}
