/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/06 15:13:24 by mjoosten         ###   ########.fr       */
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
			ft_rotate_map(window->map, 'y', 10);
		if (keycode == S)
			ft_rotate_map(window->map, 'x', 10);
		if (keycode == Q)
			ft_rotate_map(window->map, 'z', 10);
		if (keycode == D)
			ft_rotate_map(window->map, 'y', -10);
		if (keycode == W)
			ft_rotate_map(window->map, 'x', -10);
		if (keycode == E)
			ft_rotate_map(window->map, 'z', -10);
		ft_draw_map(window);
	}
	if (keycode == ESC)
		ft_close(window);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_window *window)
{
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

void	printmatrix(t_vector **matrix)
{
	printf("---Matrix--\n");
	printf("x: %.2f y: %.2f z: %.2f\n",
		matrix[0]->x, matrix[0]->y, matrix[0]->z);
	printf("x: %.2f y: %.2f z: %.2f\n",
		matrix[1]->x, matrix[1]->y, matrix[1]->z);
	printf("x: %.2f y: %.2f z: %.2f\n",
		matrix[2]->x, matrix[2]->y, matrix[2]->z);
	printf("\n");
}
