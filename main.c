/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 13:27:09 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_window	*window;

	if (argc < 2)
		ft_error("No map given");
	if (argc > 2)
		ft_error("More than one map given");
	window = ft_create_window(argv[1]);
	ft_center_map(window->map, window->size);
	ft_scale_map(window->map, ft_get_scale(window));
	ft_rotate_map(window->map, 'y', 45);
	ft_rotate_map(window->map, 'x', -45);
	window->size->x++;
	ft_draw_map(window);
	mlx_hook(window->win, DESTROY_NOTIFY, 1L << 17, ft_close, window);
	mlx_hook(window->win, MOTION_NOTIFY, 1L << 8, ft_motion, window);
	mlx_hook(window->win, BUTTON_RELEASE, 1L << 3, ft_release, window);
	mlx_mouse_hook(window->win, ft_mouse_hook, window);
	mlx_key_hook(window->win, ft_key_hook, window);
	mlx_loop(window->mlx);
}

int	ft_close(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	ft_free_array((void **)window->map);
	free(window->size);
	exit(EXIT_SUCCESS);
}

int	ft_error(char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	else
		perror(0);
	exit(EXIT_FAILURE);
}

void	printvector(t_vector *vector)
{
	printf("x: %f, y: %f, z: %f\n", vector->x, vector->y, vector->z);
}
