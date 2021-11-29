/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 13:52:04 by mjoosten         ###   ########.fr       */
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
	printf("Scale: %f\n", ft_get_scale(window->map));
	ft_scale_map(window->map, ft_get_scale(window->map));
	ft_draw_map(window);
	mlx_hook(window->win, 17, 0L, ft_close, window);
	mlx_key_hook(window->win, ft_key_hook, window);
	mlx_mouse_hook(window->win, ft_mouse_hook, window);
	mlx_loop(window->mlx);
}

void	ft_draw_map(t_window *window)
{
	t_vector	**map;

	map = window->map;
	while (*map)
	{
		mlx_pixel_put(window->mlx, window->win,
			(*map)->x, DISPLAY_Y - (*map)->y, WHITE);
		map++;
	}
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == ESC)
		ft_close(window);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_window *window)
{
	if (button == SCROLL_DOWN)
	{
		ft_scale_map(window->map, 0.85f);
		mlx_clear_window(window->mlx, window->win);
		ft_draw_map(window);
	}
	if (button == SCROLL_UP)
	{
		ft_scale_map(window->map, 1.15f);
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
	system("leaks fdf");
	exit(0);
}
