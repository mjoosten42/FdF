/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatematrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:17 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 16:41:53 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		free(scale_matrix[0]);
		free(scale_matrix[1]);
		free(scale_matrix[2]);
		free(scale_matrix);
		return (0);
	}
	ft_fill_scale_matrix(scale_matrix, scale);
	return (scale_matrix);
}

void	ft_fill_scale_matrix(t_vector **scale_matrix, float scale)
{
	scale_matrix[0]->x = scale;
	scale_matrix[0]->y = 0;
	scale_matrix[0]->z = 0;
	scale_matrix[1]->x = 0;
	scale_matrix[1]->y = scale;
	scale_matrix[1]->z = 0;
	scale_matrix[2]->x = 0;
	scale_matrix[2]->y = 0;
	scale_matrix[2]->z = scale;
}