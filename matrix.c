/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:40:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 13:44:41 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_multiply_matrix(t_vector *vector, t_vector **matrix)
{
	vector->x = vector->x * (matrix[0]->x + matrix[1]->x + matrix[2]->x);
	vector->y = vector->y * (matrix[0]->y + matrix[1]->y + matrix[2]->y);
	vector->z = vector->z * (matrix[0]->z + matrix[1]->z + matrix[2]->z);
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

void	ft_scale_map(t_vector **map, float scale)
{
	t_vector	**scale_matrix;

	scale_matrix = ft_create_scale_matrix(scale);
	while (*map)
	{
		ft_multiply_matrix(*map, scale_matrix);
		map++;
	}
	ft_free_array((void **)scale_matrix);
}
