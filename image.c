/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:11:23 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/19 16:40:52 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_create_image(t_window *window)
{
	void	*image;
	int		*buffer;
	int		depth;
	int		line_size;
	int		endian;

	image = mlx_new_image(window->mlx, DISPLAY_X, DISPLAY_Y);
	if (!image)
		return (0);
	depth = 32;
	line_size = depth / 8 * DISPLAY_X;
	endian = 0;
	buffer = (int *)mlx_get_data_addr(image, &depth, &line_size, &endian);
	for (int i = 0; i < DISPLAY_X * DISPLAY_Y; i += 4)
		buffer[i] = WHITE;
	return (image);
}
