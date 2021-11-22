/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/22 16:41:26 by mjoosten         ###   ########.fr       */
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
		ft_error();
	if (ft_create_frame(&frame, argv[1]))
		ft_error();
	if (ft_create_window(&window))
		ft_error();
	image = ft_create_image(&window);
	if (!image)
		ft_error();
	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);
	mlx_loop(window.mlx);
}

void	ft_error(void)
{
	perror(0);
	exit(1);
}

	/*
	Camera: Distance to screen(Focus) are constant. Calculate with angle with tan(X && Y / Focus).
	Model: Angle is known, distance is constant? 
 	*/