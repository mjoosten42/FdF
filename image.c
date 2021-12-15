/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:59:54 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 15:00:34 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*ft_getbuffer(void *img)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	bits_per_pixel = 32;
	size_line = DISPLAY_X;
	endian = 0;
	return ((int *)mlx_get_data_addr(
			img, &bits_per_pixel, &size_line, &endian));
}

void	ft_clear_image(int *buf)
{
	int	size;

	size = DISPLAY_X * DISPLAY_Y;
	while (size--)
		buf[size] = 0;
}

void	ft_pixel_put(t_window *window, float x, float y, int color)
{
	if ((x >= 0 && x < DISPLAY_X) && (y >= 0 && y < DISPLAY_Y))
		window->buf[(int)x + (int)y * DISPLAY_X] = color;
}
