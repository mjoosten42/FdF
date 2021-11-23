/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/23 13:59:06 by mjoosten         ###   ########.fr       */
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

int	ft_frame_to_image(t_frame *frame, int *buffer)
{
	int	i;
	int	j;
	int	height;

	int middle = (DISPLAY_Y + 1) * DISPLAY_X / 2;
	int	offset = middle - 64 * (frame->height + 1) * frame->width / 2;
	
	i = 0;
	while (i < frame->height)
	{
		j = 0;
		while (j < frame->width)
		{
			height = frame->points[i * frame->width + j];
			if (height == 0)
				buffer[offset + 100 * (i * frame->height + j)] = WHITE;
			else
				buffer[offset + 100 * (i * frame->width + j)] = 0x00FF0000;
			j++;
		}
		i++;
	}
	return (0);
}
