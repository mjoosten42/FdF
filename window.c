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
	window->size = ft_mapsize(window->map);
	window->mlx = mlx_init();
	if (window->mlx)
		window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	if (!(window->win && window->map && window->size))
	{
		if (window->win)
			mlx_destroy_window(window->mlx, window->win);
		ft_free_array((void **)window->map);
		free(window->size);
		free(window);
		return (0);
	}
	window->gradient = 0xFFFFFFFF / window->size->y;
	window->mouse = 0;
	window->x = 0;
	window->y = 0;
	return (window);
}
