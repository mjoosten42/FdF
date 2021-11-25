/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/25 16:08:52 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*ft_create_window(char *file)
{
	t_window	*window;

	window = malloc(sizeof(*window));
	if (!window)
		return (0);
	window->mlx = mlx_init();
	if (!window->mlx)
		return (ft_window_error(window, 1));
	window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	if (!window->win)
		return (ft_window_error(window, 1));
	window->img = mlx_new_image(window->mlx, DISPLAY_X, DISPLAY_Y);
	if (!window->img)
		return (ft_window_error(window, 2));
	window->buf = ft_get_buffer(window->img);
	if (!window->buf)
		return (ft_window_error(window, 3));
	window->frame = ft_create_frame(file);
	if (!window->frame)
		return (ft_window_error(window, 3));
	return (window);
}

int	*ft_get_buffer(void *img)
{
	int		depth;
	int		line_size;
	int		endian;

	depth = 32;
	line_size = depth / 8 * DISPLAY_X;
	endian = 0;
	return ((int *)mlx_get_data_addr(img, &depth, &line_size, &endian));
}

void	*ft_window_error(t_window *window, int error)
{
	if (error > 2)
		mlx_destroy_image(window->mlx, window->img);
	if (error > 1)
		mlx_destroy_window(window->mlx, window->win);
	if (error > 0)
		free(window);
	perror(0);
	return (0);
}
