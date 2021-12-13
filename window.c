/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/13 11:39:58 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*ft_create_window(char *file)
{
	t_window	*window;

	window = malloc(sizeof(*window));
	if (!window)
		ft_error(0);
	window->mlx = mlx_init();
	if (!window->mlx)
		ft_error(0);
	window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	if (!window->win)
		ft_error(0);
	window->map = ft_create_map(file);
	window->size = ft_mapsize(window->map);
	window->gradient = 16 / window->size->y;
	ft_color(window->map, window->gradient, window->size->color);
	window->mouse = 0;
	window->x = 0;
	window->y = 0;
	return (window);
}

void	ft_color(t_vector **map, float gradient, int y_min)
{
	while (*map)
	{
		(*map)->color = BLUE << (int)(gradient * ((*map)->y - y_min));
		map++;
	}
}
