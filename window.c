/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/26 16:39:38 by mjoosten         ###   ########.fr       */
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
	if (window->mlx)
		window->img = mlx_new_image(window->mlx, DISPLAY_X, DISPLAY_Y);
	window->buf = ft_get_buffer(window->img);
	window->width = ft_get_width(file);
	window->height = ft_get_height(file);
	window->scale = ft_get_scale(window->width, window->height);
	if (!(window->win && window->buf && window->scale))
	{
		if (window->img)
			mlx_destroy_image(window->mlx, window->img);
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
	window->img = 0;
	window->buf = 0;
	window->width = 0;
	window->height = 0;
	window->scale = 0.f;
}

int	*ft_get_buffer(void *img)
{
	int		depth;
	int		line_size;
	int		endian;

	if (!img)
		return (0);
	depth = 32;
	line_size = depth / 8 * DISPLAY_X;
	endian = 0;
	return ((int *)mlx_get_data_addr(img, &depth, &line_size, &endian));
}
