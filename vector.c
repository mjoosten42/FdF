/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:36:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 16:37:01 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vector_add(t_vector *move, t_vector *vector)
{
	move->x = move->x + vector->x;
	move->y = move->y + vector->y;
	move->z = move->z + vector->z;
}

void	ft_vector_subtract(t_vector *move, t_vector *vector)
{
	move->x = move->x - vector->x;
	move->y = move->y - vector->y;
	move->z = move->z - vector->z;
}

void	ft_vector_multiply(t_vector *vector, t_vector **matrix)
{
	vector->x = vector->x * (matrix[0]->x + matrix[1]->x + matrix[2]->x);
	vector->y = vector->y * (matrix[0]->y + matrix[1]->y + matrix[2]->y);
	vector->z = vector->z * (matrix[0]->z + matrix[1]->z + matrix[2]->z);
}
