/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/23 16:38:59 by mjoosten         ###   ########.fr       */
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

int	ft_get_scale(t_frame *frame);

int	ft_frame_to_image(t_frame *frame, int *buffer)
{
	int	i;
	int	j;
	int	offset;
	int	scale;

	scale = ft_get_scale(frame) / 8;
	offset = ((DISPLAY_X - scale * frame->width) / 2)
		+ ((DISPLAY_Y - scale * frame->height) / 2) * DISPLAY_X;
	i = 0;
	while (i < frame->height)
	{
		j = 0;
		while (j < frame->width)
		{
			buffer[offset + scale * (i * DISPLAY_X + j)] = WHITE;
			if (frame->points[i * frame->width + j] != 0)
				buffer[offset + scale * (i * DISPLAY_X + j)] = 0x00FF0000;
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_get_scale(t_frame *frame)
{
	int	scale_x;
	int	scale_y;

	scale_x = DISPLAY_X / frame->width;
	scale_y = DISPLAY_Y / frame->height;
	if (scale_x > scale_y)
		return (scale_y);
	return (scale_x);
}
