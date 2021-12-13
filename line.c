/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:43:03 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/13 15:43:25 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_window *window, t_vector *first, t_vector *second)
{
	t_vector	*vector;
	t_vector	*normal;
	float		yhalf;

	vector = ft_vectornew(first->x, first->y, 0);
	vector->height = first->height;
	normal = ft_vectornormal(first, second);
	normal->height = (second->height - first->height) / normal->z;
	vector->x += 0.5f * DISPLAY_X;
	yhalf = 0.5f * DISPLAY_Y;
	while ((int)normal->z--)
	{
		mlx_pixel_put(window->mlx, window->win,
			vector->x, -vector->y + yhalf,
			BLUE << (int)(0.5f + window->gradient
				* (vector->height - window->size->height)));
		ft_vectoradd(vector, normal);
		vector->height += normal->height;
	}
	free(vector);
	free(normal);
}
