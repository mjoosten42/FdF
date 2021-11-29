/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:01:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 13:49:44 by mjoosten         ###   ########.fr       */
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
	{
		free(window);
		return (0);
	}
	window->win = mlx_new_window(window->mlx, DISPLAY_X, DISPLAY_Y, "FdF");
	if (!window->win)
	{
		free(window);
		return (0);
	}
	window->map = ft_create_map(file);
	if (!window->map)
	{
		mlx_destroy_window(window->mlx, window->win);
		free(window);
		return (0);
	}
	return (window);
}
