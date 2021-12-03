/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:43:03 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/03 10:46:06 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_window *window, t_vector *first, t_vector *second)
{
	t_vector	**scale_matrix;
	t_vector	*a;
	t_vector	*b;
	float		length;

	if (first->x == second->x && first->y == second->y)
		return ;
	a = ft_vectornew(first->x, first->y, 0);
	b = ft_vectornew(second->x, second->y, 0);
	ft_vectorsubtract(b, a);
	length = sqrt(b->x * b->x + b->y * b->y);
	scale_matrix = ft_matrix_scale_new(1.f / length);
	if (scale_matrix)
	{
		ft_vectormultiply(b, scale_matrix);
		while ((int)length--)
		{
			ft_vectoradd(a, b);
			mlx_pixel_put(window->mlx, window->win,
				a->x, DISPLAY_Y - a->y, WHITE);
		}
	}
	ft_free_array((void **)scale_matrix);
	free(a);
	free(b);
}
