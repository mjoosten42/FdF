/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/19 16:24:28 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_window	window;
	char		*image;

	(void)argv;
	if (argc != 2)
		return (1);
	if (ft_create_window(&window))
		return (2);
	image = ft_create_image(&window);
	mlx_put_image_to_window(window.mlx, window.win, image, 0, 0);
	mlx_loop(window.mlx);
}
