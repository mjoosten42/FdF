/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 14:57:07 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_newheight(t_vector **map, t_vector *size)
{
	while (*map)
		(*map++)->height -= size->height;
}

t_window	*ft_create_window(char *file)
{
	t_window	*window;

	window = malloc(sizeof(*window));
	if (!window)
		ft_error(0);
	window->map = ft_create_map(file);
	window->size = ft_mapsize(window->map);
	ft_newheight(window->map, window->size);
	window->mlx = mlx_init();
	if (!window->mlx)
		ft_error(0);
	window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	window->img = mlx_new_image(window->mlx, DISPLAY_X, DISPLAY_Y);
	if (!window->win || !window->img)
		ft_error(0);
	window->buf = ft_getbuffer(window->img);
	if (!window->buf)
		ft_error(0);
	window->gradient = 0;
	if (window->size->y)
		window->gradient = 20 / window->size->y;
	window->mouse = 0;
	window->x = 0;
	window->y = 0;
	return (window);
}
