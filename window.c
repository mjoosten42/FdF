/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 11:06:50 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*ft_create_window(char *file)
{
	t_window	*window;

	window = malloc(sizeof(*window));
	if (!window)
		return (0);
	ft_window_init(window);
	window->mlx = mlx_init();
	if (window->mlx)
		window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	window->matrix = ft_create_matrix(file);
	window->scale = ft_get_scale(window->x_max, window->y_max, window->z_max);
	if (!(window->win && window->scale))
	{
		if (window->win)
			mlx_destroy_window(window->mlx, window->win);
		free(window);
	}
	return (window);
}

void	ft_window_init(t_window *window)
{
	window->mlx = 0;
	window->win = 0;
	window->x_max = 0;
	window->y_max = 0;
	window->z_max = 0;
}
