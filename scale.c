/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:17 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/07 11:47:03 by mjoosten         ###   ########.fr       */
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
	t_vector	*size;
	float		diagonal;

	size = ft_mapsize(map);
	if (!size)
		return (0);
	diagonal = sqrt(size->x * size->x + size->z * size->z);
	diagonal = sqrt(diagonal * diagonal + size->y * size->y);
	free(size);
	if (DISPLAY_X < DISPLAY_Y)
		return ((float)DISPLAY_X / diagonal);
	return ((float)DISPLAY_Y / diagonal);
}
