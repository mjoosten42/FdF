/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/03 11:27:06 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_window	*window;

	if (argc != 2)
		return (1);
	window = ft_create_window(argv[1]);
	if (!window)
		return (1);
	ft_scale_map(window->map, ft_get_scale(window->map));
	ft_rotate_map(window->map, 'y', -45);
	ft_rotate_map(window->map, 'x', -30);
	ft_center_map(window->map);
	ft_draw_map(window);
	mlx_hook(window->win, 17, 0L, ft_close, window);
	mlx_key_hook(window->win, ft_key_hook, window);
	mlx_mouse_hook(window->win, ft_mouse_hook, window);
	mlx_loop(window->mlx);
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == A || keycode == S || keycode == D
		|| keycode == W || keycode == Q || keycode == E)
	{
		if (keycode == A)
			ft_rotate_map(window->map, 'y', 30);
		if (keycode == S)
			ft_rotate_map(window->map, 'x', 30);
		if (keycode == Q)
			ft_rotate_map(window->map, 'z', -30);
		if (keycode == D)
			ft_rotate_map(window->map, 'y', -30);
		if (keycode == W)
			ft_rotate_map(window->map, 'x', -30);
		if (keycode == E)
			ft_rotate_map(window->map, 'z', 30);
		ft_center_map(window->map);
		mlx_clear_window(window->mlx, window->win);
		ft_draw_map(window);
	}
	if (keycode == ESC)
		ft_close(window);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_window *window)
{
	float	scale;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		scale = 0.15f;
		if (button == SCROLL_UP)
			scale = 1 + scale;
		if (button == SCROLL_DOWN)
			scale = 1 - scale;
		ft_scale_map(window->map, scale);
		//ft_center_map(window->map);
		mlx_clear_window(window->mlx, window->win);
		ft_draw_map(window);
	}
	(void)x;
	(void)y;
	return (0);
}

int	ft_close(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	ft_free_array((void **)window->map);
	free(window);
	//system("leaks fdf");
	exit(0);
}
