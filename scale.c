/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:17 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/30 12:58:29 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	**ft_matrix_scale_new(float scale)
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

float	ft_get_scale(t_vector **map)
{
	t_vector	*max;
	int			display_smallest;
	float		diagonal;

	display_smallest = DISPLAY_X;
	if (display_smallest < DISPLAY_Y)
		display_smallest = DISPLAY_Y;
	max = ft_get_map_max(map);
	if (!max)
		return (0);
	diagonal = sqrt(max->x * max->x + max->y * max->y);
	diagonal = sqrt(max->z * max->z + diagonal * diagonal);
	free(max);
	return ((float)display_smallest / diagonal);
}
