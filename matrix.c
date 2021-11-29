/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:40:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 15:49:13 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrix_add(t_vector **map, t_vector *vector)
{
	while (*map)
	{
		(*map)->x = (*map)->x + vector->x;
		(*map)->y = (*map)->y + vector->y;
		(*map)->z = (*map)->z + vector->z;
		map++;
	}
}

void	ft_matrix_multiply(t_vector *scale, t_vector **matrix)
{
	scale->x = scale->x * (matrix[0]->x + matrix[1]->x + matrix[2]->x);
	scale->y = scale->y * (matrix[0]->y + matrix[1]->y + matrix[2]->y);
	scale->z = scale->z * (matrix[0]->z + matrix[1]->z + matrix[2]->z);
}

t_vector	*ft_create_move_matrix(int x, int y, int z)
{
	t_vector	*vector;

	vector = malloc(sizeof(*vector));
	if (!vector)
		return (0);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector	**ft_create_scale_matrix(float scale)
{
	t_vector	**scale_matrix;

	scale_matrix = malloc(sizeof(*scale_matrix) * 4);
	if (!scale_matrix)
		return (0);
	scale_matrix[0] = malloc(sizeof(t_vector));
	scale_matrix[1] = malloc(sizeof(t_vector));
	scale_matrix[2] = malloc(sizeof(t_vector));
	scale_matrix[3] = 0;
	if (!(scale_matrix[0] && scale_matrix[1] && scale_matrix[2]))
	{
		free(scale_matrix);
		return (0);
	}
	scale_matrix[0]->x = scale;
	scale_matrix[0]->y = 0;
	scale_matrix[0]->z = 0;
	scale_matrix[1]->x = 0;
	scale_matrix[1]->y = scale;
	scale_matrix[1]->z = 0;
	scale_matrix[2]->x = 0;
	scale_matrix[2]->y = 0;
	scale_matrix[2]->z = scale;
	return (scale_matrix);
}

void	ft_vector_invert(t_vector *vector)
{
	vector->x = -vector->x;
	vector->y = -vector->y;
	vector->z = -vector->z;
}
