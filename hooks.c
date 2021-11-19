/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/19 15:31:16 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ESC 53

int	ft_make_window(t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		return (1);
	window->win = mlx_new_window(window->mlx, 1024, 720, "fdf");
	if (!window->win)
		return (2);
	mlx_hook(window->win, 17, 1L << 17, ft_close, window);
	mlx_key_hook(window->win, ft_key_hook, window);
	mlx_loop(window->mlx);
	return (0);
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == ESC)
		mlx_destroy_window(window->mlx, window->win);
	return (0);
}

int	ft_close(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	return (0);
}
