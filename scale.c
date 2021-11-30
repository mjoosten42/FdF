/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:17 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/30 11:52:23 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_vector	*ft_get_map_max(t_vector **map)
{
	t_vector	*max;

	max = malloc(sizeof(*max));
	if (!max)
		return (0);
	max->x = (*map)->x;
	max->y = (*map)->y;
	max->z = (*map)->z;
	while (*map)
	{
		if ((*map)->x > max->x)
			max->x = (*map)->x;
		if ((*map)->y > max->y)
			max->y = (*map)->y;
		if ((*map)->z > max->z)
			max->z = (*map)->z;
		map++;
	}
	return (max);
}

t_vector	*ft_get_map_min(t_vector **map)
{
	t_vector	*min;

	min = malloc(sizeof(*min));
	if (!min)
		return (0);
	min->x = (*map)->x;
	min->y = (*map)->y;
	min->z = (*map)->z;
	while (*map)
	{
		if ((*map)->x < min->x)
			min->x = (*map)->x;
		if ((*map)->y < min->y)
			min->y = (*map)->y;
		if ((*map)->z < min->z)
			min->z = (*map)->z;
		map++;
	}
	return (min);
}
