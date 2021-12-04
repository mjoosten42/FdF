/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:02:29 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/04 14:57:58 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*ft_mapcenter(t_vector **map)
{
	t_vector	*center;
	int			points;

	points = 0;
	center = ft_vectornew(0, 0, 0);
	if (!center)
		return (0);
	while (*map)
	{
		ft_vectoradd(center, *map++);
		points++;
	}
	center->x = center->x / points;
	center->y = center->y / points;
	center->z = center->z / points;
	return (center);
}

t_vector	*ft_mapmax(t_vector **map)
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

t_vector	*ft_mapmin(t_vector **map)
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
