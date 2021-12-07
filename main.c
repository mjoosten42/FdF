/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/06 18:56:30 by mjoosten         ###   ########.fr       */
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
	ft_center_map(window->map, window->size);
	ft_scale_map(window->map, ft_get_scale(window->map));
	ft_draw_map(window);
	mlx_hook(window->win, DESTROY_NOTIFY, 1L << 17, ft_close, window);
	mlx_hook(window->win, MOTION_NOTIFY, 1L << 8, ft_motion, window);
	mlx_hook(window->win, BUTTON_RELEASE, 1L << 3, ft_release, window);
	mlx_mouse_hook(window->win, ft_mouse_hook, window);
	mlx_key_hook(window->win, ft_key_hook, window);
	mlx_loop(window->mlx);
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == ESC)
		ft_close(window);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_window *window)
{
	if (button == LEFT_MOUSE_BUTTON)
		window->mouse = 1;
	if (button == SCROLL_DOWN)
	{
		ft_scale_map(window->map, 0.85f);
		ft_draw_map(window);
	}
	if (button == SCROLL_UP)
	{
		ft_scale_map(window->map, 1.15f);
		ft_draw_map(window);
	}
	(void)x;
	(void)y;
	return (0);
}

int	ft_motion(int x, int y, t_window *window)
{
	float	sensitivity;

	sensitivity = 0.1f;
	if (window->mouse)
	{
		if (x != window->x)
		{
			ft_rotate_map(window->map, 'y', sensitivity * (x - window->x));
			ft_draw_map(window);
		}
		if (y != window->y)
		{
			ft_rotate_map(window->map, 'x', sensitivity * (window->y - y));
			ft_draw_map(window);
		}
	}
	window->x = x;
	window->y = y;
	return (0);
}

int	ft_release(int button, int x, int y, t_window *window)
{
	(void)x;
	(void)y;
	if (button == LEFT_MOUSE_BUTTON)
		window->mouse = 0;
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

void	printvector(t_vector *vector)
{
	printf("x: %.2f y: %.2f z: %.2f\n", vector->x, vector->y, vector->z);
}
