/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:17 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/06 14:00:02 by mjoosten         ###   ########.fr       */
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
	float		diagonal;
	float		scale_x;
	float		scale_y;

	max = ft_mapmax(map);
	if (!max)
		return (0);
	diagonal = sqrt(max->x * max->x + max->z * max->z);
	scale_x = (float)DISPLAY_X / diagonal;
	scale_y = 0.5f * (float)DISPLAY_Y / max->y;
	free(max);
	if (scale_x < scale_y)
		return (scale_x / 1.2f);
	return (scale_y / 1.2f);
}

t_vector	*ft_mapmax(t_vector **map)
{
	t_vector	*max;
	float		y_min;

	max = ft_vectornew(map[0]->x, map[0]->y, map[0]->z);
	while (*map)
	{
		if ((*map)->x > max->x)
			max->x = (*map)->x;
		if ((*map)->y > max->y)
			max->y = (*map)->y;
		if ((*map)->y < y_min)
			y_min = (*map)->y;
		if ((*map)->z > max->z)
			max->z = (*map)->z;
		map++;
	}
	max->y = max->y - y_min;
	return (max);
}
