/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/04 15:06:55 by mjoosten         ###   ########.fr       */
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
	if (window->mlx)
		window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	window->map = ft_create_map(file);
	window->width = ft_get_width(file);
	if (!(window->win && window->map && window->width))
	{
		if (window->win)
			mlx_destroy_window(window->mlx, window->win);
		ft_free_array((void **)window->map);
		free(window);
		return (0);
	}
	return (window);
}

int	ft_get_width(char *file)
{
	char	**strs;
	char	*str;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	str = ft_get_next_line(fd);
	strs = ft_split(str, ' ');
	i = 0;
	if (strs)
		while (strs[i])
			i++;
	ft_free_array((void **)strs);
	free(str);
	close(fd);
	return (i);
}
