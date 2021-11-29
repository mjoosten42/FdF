/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:14:18 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 15:14:30 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_get_z_max(t_vector **map)
{
	float	z_max;

	z_max = (*map)->z;
	while (*map)
	{
		if ((*map)->z > z_max)
			z_max = (*map)->z;
		map++;
	}
	return (z_max);
}

float	ft_get_z_min(t_vector **map)
{
	float	z_min;

	z_min = (*map)->z;
	while (*map)
	{
		if ((*map)->z < z_min)
			z_min = (*map)->z;
		map++;
	}
	return (z_min);
}
