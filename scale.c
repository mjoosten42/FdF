/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:17 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/04 14:05:57 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	**ft_matrix_scale_new(float scale)
{
	t_vector	**scale_matrix;

	scale_matrix = malloc(sizeof(*scale_matrix) * 4);
	if (!scale_matrix)
		return (0);
	scale_matrix[0] = ft_vectornew(scale, 0, 0);
	scale_matrix[1] = ft_vectornew(0, scale, 0);
	scale_matrix[2] = ft_vectornew(0, 0, scale);
	scale_matrix[3] = 0;
	if (!(scale_matrix[0] && scale_matrix[1] && scale_matrix[2]))
	{
		free(scale_matrix[0]);
		free(scale_matrix[1]);
		free(scale_matrix[2]);
		free(scale_matrix);
		return (0);
	}
	return (scale_matrix);
}

float	ft_get_scale(t_vector **map)
{
	t_vector	*max;
	int			display_smallest;
	float		diagonal;

	display_smallest = DISPLAY_X;
	if (display_smallest > DISPLAY_Y)
		display_smallest = DISPLAY_Y;
	max = ft_mapmax(map);
	if (!max)
		return (0);
	diagonal = sqrt(max->x * max->x + max->y * max->y);
	diagonal = sqrt(max->z * max->z + diagonal * diagonal);
	free(max);
	return ((float)display_smallest / diagonal);
}
