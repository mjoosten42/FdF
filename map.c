/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:22 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/11 16:33:32 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*ft_mapsize(t_vector **map)
{
	t_vector	*size;
	float		y_min;

	if (!map)
		return (0);
	if (!map[0])
		return (0);
	size = ft_vectornew(map[0]->x, map[0]->y, map[0]->z);
	while (*map)
	{
		if ((*map)->x > size->x)
			size->x = (*map)->x;
		if ((*map)->y > size->y)
			size->y = (*map)->y;
		if ((*map)->y < y_min)
			y_min = (*map)->y;
		if ((*map)->z > size->z)
			size->z = (*map)->z;
		map++;
	}
	size->y = size->y - y_min;
	size->height = y_min;
	return (size);
}

void	ft_center_map(t_vector **map, t_vector *size)
{
	float	x;
	float	y;
	float	z;

	x = 0.5f * size->x;
	y = 0.5f * size->y;
	z = 0.5f * size->z;
	while (*map)
	{
		(*map)->x -= x;
		(*map)->y += y;
		(*map)->z -= z;
		map++;
	}
}

void	ft_scale_map(t_vector **map, float scale)
{
	t_vector	**scale_matrix;

	scale_matrix = ft_matrix_scale_new(scale);
	if (!scale_matrix)
		return ;
	while (*map)
		ft_vectormultiply(*map++, scale_matrix);
	ft_free_array((void **)scale_matrix);
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
	float	xhalf;
	float	yhalf;
	int		i;

	xhalf = 0.5f * DISPLAY_X;
	yhalf = 0.5f * DISPLAY_Y;
	i = 0;
	mlx_clear_window(window->mlx, window->win);
	while (window->map[i])
	{
		printf("%f\n", window->gradient * window->map[i]->height);
		mlx_pixel_put(window->mlx, window->win,
			window->map[i]->x + xhalf,
			window->map[i]->y + yhalf,
			WHITE >> (int)(window->map[i]->height * window->gradient));
		// Trying coloring by bitshifting white.
		// if (i >= (int)window->size->x)
		// 	ft_drawline(window,
		// 		window->map[i],
		// 		window->map[i - (int)window->size->x]);
		// if (i % (int)window->size->x)
		// 	ft_drawline(window,
		// 		window->map[i],
		// 		window->map[i - 1]);
		i++;
	}
}
