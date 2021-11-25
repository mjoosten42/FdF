/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/25 12:46:02 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_window	window;
	t_frame		frame;
	int			*image;

	(void)argv;
	if (argc != 2)
		return (1);
	if (ft_create_frame(&frame, argv[1]))
		ft_error();
	if (ft_create_window(&window))
		ft_error();
	image = ft_create_image(&window);
	if (!image)
		ft_error();
	if (ft_frame_to_image(&frame, image))
		ft_error();
	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);
	mlx_loop(window.mlx);
}

void	ft_error(void)
{
	perror(0);
	exit(1);
}

float	ft_get_scale(t_frame *frame);

int	ft_frame_to_image(t_frame *frame, int *buffer)
{
	int		i;
	int		j;
	int		offset;
	float	scale;

	scale = ft_get_scale(frame) / 1.2f;
	offset = ((DISPLAY_X - (int)(scale * frame->width)) / 2)
		+ DISPLAY_X * ((DISPLAY_Y - (int)(scale * frame->height)) / 2);
	i = 0;
	while (i < frame->height)
	{
		j = 0;
		while (j < frame->width)
		{
			if (frame->points[i * frame->width + j])
				buffer[offset + DISPLAY_X * (int)(i * scale) + (int)(j * scale)] = 0x00FF0000;
			else
				buffer[offset + DISPLAY_X * (int)(i * scale) + (int)(j * scale)] = WHITE;
			j++;
		}
		i++;
	}
	return (0);
}

float	ft_get_scale(t_frame *frame)
{
	float	scale_x;
	float	scale_y;

	scale_x = (float)DISPLAY_X / (float)frame->width;
	scale_y = (float)DISPLAY_Y / (float)frame->height;
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}
