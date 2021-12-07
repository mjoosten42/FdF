/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:22 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/07 11:55:39 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int	i;

	i = 0;
	mlx_clear_window(window->mlx, window->win);
	while (window->map[i])
	{
		mlx_pixel_put(window->mlx, window->win,
			window->map[i]->x + DISPLAY_X * 0.5f,
			window->map[i]->y + DISPLAY_Y * 0.5f,
			WHITE);
		if (i > (int)window->max->x)
			ft_drawline(window, window->map[i],
				window->map[i - (int)window->max->x]);
		if (i % (int)window->max->x)
			ft_drawline(window, window->map[i],
				window->map[i - 1]);
		i++;
	}
}
