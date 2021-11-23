/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/23 11:47:30 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_create_window(t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		return (1);
	window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	if (!window->win)
		return (2);
	mlx_hook(window->win, 17, 0L, ft_close, window);
	mlx_key_hook(window->win, ft_key_hook, window);
	return (0);
}

int	*ft_create_image(t_window *window)
{
	int		depth;
	int		line_size;
	int		endian;

	window->img = mlx_new_image(window->mlx, DISPLAY_X, DISPLAY_Y);
	if (!window->img)
		return (0);
	depth = 32;
	line_size = depth / 8 * DISPLAY_X;
	endian = 0;
	return ((int *)mlx_get_data_addr(window->img, &depth, &line_size, &endian));
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == ESC)
		ft_close(window);
	return (0);
}

int	ft_close(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_image(window->mlx, window->img);
	exit(0);
	return (0);
}
