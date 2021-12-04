/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:43:03 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/04 16:15:06 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_window *window, t_vector *first, t_vector *second)
{
	t_vector	**scale_matrix;
	t_vector	*a;
	t_vector	*b;
	float		length;

	a = ft_vectornew(first->x, first->y, 0);
	b = ft_vectornew(second->x, second->y, 0);
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
	while ((int)length--)
	{
		ft_vectoradd(a, b);
		ft_drawboldline(window, a->x, DISPLAY_Y - a->y);
	}
	ft_free_array((void **)scale_matrix);
	free(a);
	free(b);
}

void	ft_drawboldline(t_window *window, int x, int y)
{
	mlx_pixel_put(window->mlx, window->win, x, y, WHITE);
	mlx_pixel_put(window->mlx, window->win, x + 1, y, WHITE);
	mlx_pixel_put(window->mlx, window->win, x, y + 1, WHITE);
	mlx_pixel_put(window->mlx, window->win, x - 1, y, WHITE);
	mlx_pixel_put(window->mlx, window->win, x, y - 1, WHITE);
}
