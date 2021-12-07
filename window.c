/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/07 11:51:17 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*ft_create_window(char *file)
{
	t_window	*window;

	window = malloc(sizeof(*window));
	if (!window)
		return (0);
	window->map = ft_create_map(file);
	window->max = ft_mapmax(window->map);
	window->mlx = mlx_init();
	if (window->mlx)
		window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	if (!(window->win && window->map && window->max))
	{
		if (window->win)
			mlx_destroy_window(window->mlx, window->win);
		ft_free_array((void **)window->map);
		free(window->max);
		free(window);
		return (0);
	}
	return (window);
}

t_vector	*ft_mapmax(t_vector **map)
{
	t_vector	*max;
	float		y_min;

	max = ft_vectornew(map[0]->x, map[0]->y, map[0]->z);
	while (*map)
	{
		if ((*map)->x > max->x)
			max->x = (*map)->x;
		if ((*map)->y > max->y)
			max->y = (*map)->y;
		if ((*map)->y < y_min)
			y_min = (*map)->y;
		if ((*map)->z > max->z)
			max->z = (*map)->z;
		map++;
	}
	max->x++;
	max->y = max->y - y_min;
	max->z++;
	return (max);
}
