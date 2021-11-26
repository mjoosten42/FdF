/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/26 16:32:40 by mjoosten         ###   ########.fr       */
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
	ft_draw_points(window, argv[1]);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	mlx_hook(window->win, 17, 0L, ft_close, window);
	mlx_key_hook(window->win, ft_key_hook, window);
	mlx_loop(window->mlx);
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == ESC)
		ft_close(window);
	return (0);
}

int	ft_close(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	free(window);
	exit(0);
}

void	ft_draw_points(t_window *window, char *file)
{
	char	*str;
	int		fd;
	int		row;

	row = 0;
	fd = open(file, O_RDONLY);
	str = ft_get_next_line(fd);
	while (str)
	{
		if (ft_draw_row(window, str, row))
		{
			free(str);
			close(fd);
			return ;
		}
		free(str);
		str = ft_get_next_line(fd);
	}
	close(fd);
}

int	ft_draw_row(t_window *window, char *str, int row)
{
	char	**strs;
	int		i;
	int		x;
	int		y;

	strs = ft_split(str, ' ');
	if (!strs)
		return (1);
	i = 0;
	while (strs[i])
	{
		x = (int)(window->scale * i);
		y = (int)(window->scale * row);
		window->buf[x + y * DISPLAY_X] = WHITE;
	}
	free(strs);
	return (0);
}
