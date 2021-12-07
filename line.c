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
	t_vector	**scale_matrix;
	t_vector	*a;
	t_vector	*b;
	float		length;
	int			color;

	a = ft_vectornew(first->x, first->y, first->height);
	b = ft_vectornew(second->x, second->y, second->height);
	if (!a || !b || (first->x == second->x && first->y == second->y))
	{
		free(a);
		free(b);
		return ;
	}
	ft_vectorsubtract(b, a);
	length = sqrt(b->x * b->x + b->y * b->y);
	scale_matrix = ft_matrix_scale_new(1.f / length);
	if (!scale_matrix)
		return ;
	ft_vectormultiply(b, scale_matrix);
	color = WHITE / window->max->y;
	while ((int)length--)
	{
		ft_vectoradd(a, b);
		ft_boldline(window, a->x + DISPLAY_X * 0.5f,
			a->y + DISPLAY_Y * 0.5f, (abs)(a->height * color));
	}
	ft_free_array((void **)scale_matrix);
	free(a);
	free(b);
}

void	ft_boldline(t_window *window, float x, float y, int color)
{
	mlx_pixel_put(window->mlx, window->win,
		x, y, color);
	mlx_pixel_put(window->mlx, window->win,
		x + 1, y, color);
	mlx_pixel_put(window->mlx, window->win,
		x, y + 1, color);
}

void	ft_drawstep(t_vector *t_vector, int length)
{

}