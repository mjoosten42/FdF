/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:56:09 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/13 15:20:21 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	sensitivity = 0.25f;
	if (window->mouse)
	{
		if (x != window->x)
		{
			ft_rotate_map(window->map, 'y', sensitivity * (window->x - x));
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
	if (button == LEFT_MOUSE_BUTTON)
		window->mouse = 0;
	(void)x;
	(void)y;
	return (0);
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == ESC)
		ft_close(window);
	return (0);
}
