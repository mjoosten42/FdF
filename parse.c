/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:02:53 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/26 15:34:07 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_frame_to_image(t_window *window)
{
	int		pixel;
	int		i;
	int		j;

	i = 0;
	while (i < window->frame->height)
	{
		j = 0;
		while (j < window->frame->width)
		{
			pixel = ft_get_pixel(window, j, i);
			window->buf[pixel] = WHITE;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(window->mlx, window->win, window->img,
		DISPLAY_X / 2 - (int)(window->frame->width * window->scale / 2),
		DISPLAY_Y / 2 - (int)(window->frame->height * window->scale / 2));
}

int	ft_get_pixel(t_window *window, int x, int y)
{
	return (DISPLAY_X * (int)(y * window->scale) + (int)(x * window->scale));
}
