/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:49 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/03 15:25:44 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	**ft_matrix_rotate_new(char c, float angle)
{
	t_vector	**rotate_matrix;

	rotate_matrix = malloc(sizeof(*rotate_matrix) * 4);
	if (!rotate_matrix)
		return (0);
	ft_fill_rotate_matrix(rotate_matrix, c, angle * M_PI / 180);
	if (!(rotate_matrix[0] && rotate_matrix[1] && rotate_matrix[2]))
	{
		free(rotate_matrix[0]);
		free(rotate_matrix[1]);
		free(rotate_matrix[2]);
		free(rotate_matrix);
		return (0);
	}
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
