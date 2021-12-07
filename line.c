/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:43:03 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/07 12:03:12 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_window *window, t_vector *first, t_vector *second)
{
	t_vector	*a;
	t_vector	*b;
	int			length;

	a = ft_vectornew(first->x, first->y, 0);
	b = ft_vectornew(second->x, second->y, 0);
	if (!a || !b || (first->x == second->x && first->y == second->y))
	{
		free(a);
		free(b);
		return ;
	}
	ft_vectorsubtract(b, a);
	length = (int)ft_vectornormal(b);
	while (length--)
	{
		ft_vectoradd(a, b);
		mlx_pixel_put(window->mlx, window->win,
			a->x + 0.5f * (float)DISPLAY_X,
			a->y + 0.5f * (float)DISPLAY_Y,
			WHITE);
	}
	free(a);
	free(b);
}

float	ft_vectornormal(t_vector *vector)
{
	t_vector	**scale_matrix;
	float		length;

	length = sqrt(vector->x * vector->x + vector->y * vector->y);
	scale_matrix = ft_matrix_scale_new(1.f / length);
	if (!scale_matrix)
		return (0);
	ft_vectormultiply(vector, scale_matrix);
	ft_free_array((void **)scale_matrix);
	return (length);
}
