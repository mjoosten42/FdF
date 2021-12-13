/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:17 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/13 15:29:52 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	**ft_matrix_scale_new(float scale)
{
	t_vector	**scale_matrix;

	scale_matrix = malloc(sizeof(*scale_matrix) * 4);
	if (!scale_matrix)
		ft_error(0);
	scale_matrix[0] = ft_vectornew(scale, 0, 0);
	scale_matrix[1] = ft_vectornew(0, scale, 0);
	scale_matrix[2] = ft_vectornew(0, 0, scale);
	scale_matrix[3] = 0;
	return (scale_matrix);
}

float	ft_get_scale(t_window *window)
{
	float		diagonal;

	diagonal = sqrt(
			window->size->x * window->size->x
			+ window->size->z * window->size->z);
	diagonal = sqrt(diagonal * diagonal
			+ window->size->y * window->size->y);
	if (DISPLAY_X < DISPLAY_Y)
		return ((float)DISPLAY_X / diagonal);
	return ((float)DISPLAY_Y / diagonal);
}

t_vector	**ft_matrix_rotate_new(char c, float angle)
{
	t_vector	**rotate_matrix;

	rotate_matrix = malloc(sizeof(*rotate_matrix) * 4);
	if (!rotate_matrix)
		ft_error(0);
	ft_fill_rotate_matrix(rotate_matrix, c, angle * M_PI / 180);
	return (rotate_matrix);
}

void	ft_fill_rotate_matrix(t_vector **matrix, char c, double radian)
{
	if (c == 'x')
	{
		matrix[0] = ft_vectornew(1, 0, 0);
		matrix[1] = ft_vectornew(0, cos(radian), -sin(radian));
		matrix[2] = ft_vectornew(0, sin(radian), cos(radian));
	}
	if (c == 'y')
	{
		matrix[0] = ft_vectornew(cos(radian), 0, sin(radian));
		matrix[1] = ft_vectornew(0, 1, 0);
		matrix[2] = ft_vectornew(-sin(radian), 0, cos(radian));
	}
	if (c == 'z')
	{
		matrix[0] = ft_vectornew(cos(radian), -sin(radian), 0);
		matrix[1] = ft_vectornew(sin(radian), cos(radian), 0);
		matrix[2] = ft_vectornew(0, 0, 1);
	}
	matrix[3] = 0;
}
