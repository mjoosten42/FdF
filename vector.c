/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:36:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/30 12:01:22 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*ft_vectornew(int x, int y, int z)
{
	t_vector	*vector;

	vector = malloc(sizeof(*vector));
	if (!vector)
		return (0);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

void	ft_vectoradd(t_vector *vector, t_vector *move)
{
	vector->x = vector->x + move->x;
	vector->y = vector->y + move->y;
	vector->z = vector->z + move->z;
}

void	ft_vectorsubtract(t_vector *vector, t_vector *move)
{
	vector->x = vector->x - move->x;
	vector->y = vector->y - move->y;
	vector->z = vector->z - move->z;
}

void	ft_vectormultiply(t_vector *vector, t_vector **matrix)
{
	vector->x = vector->x * (matrix[0]->x + matrix[1]->x + matrix[2]->x);
	vector->y = vector->y * (matrix[0]->y + matrix[1]->y + matrix[2]->y);
	vector->z = vector->z * (matrix[0]->z + matrix[1]->z + matrix[2]->z);
}
