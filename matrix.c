/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:40:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 16:38:38 by mjoosten         ###   ########.fr       */
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

void	ft_matrix_subtract(t_vector **map, t_vector *vector)
{
	while (*map)
	{
		(*map)->x = (*map)->x - vector->x;
		(*map)->y = (*map)->y - vector->y;
		(*map)->z = (*map)->z - vector->z;
		map++;
	}
}

void	ft_matrix_multiply(t_vector **map, t_vector **matrix)
{
	while (*map)
	{
		(*map)->x = (*map)->x * (matrix[0]->x + matrix[1]->x + matrix[2]->x);
		(*map)->y = (*map)->y * (matrix[0]->y + matrix[1]->y + matrix[2]->y);
		(*map)->z = (*map)->z * (matrix[0]->z + matrix[1]->z + matrix[2]->z);
		map++;
	}
}
