/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:36:25 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/13 15:35:58 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*ft_vectornew(float x, float y, float z)
{
	t_vector	*vector;

	vector = malloc(sizeof(*vector));
	if (!vector)
		ft_error(0);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

void	ft_vectoradd(t_vector *vector, t_vector *move)
{
	if (!vector || !move)
		return ;
	vector->x = vector->x + move->x;
	vector->y = vector->y + move->y;
	vector->z = vector->z + move->z;
}

void	ft_vectorsubtract(t_vector *vector, t_vector *move)
{
	if (!vector || !move)
		return ;
	vector->x = vector->x - move->x;
	vector->y = vector->y - move->y;
	vector->z = vector->z - move->z;
}

void	ft_vectormultiply(t_vector *vector, t_vector **matrix)
{
	float	x;
	float	y;
	float	z;

	if (!vector || !matrix)
		return ;
	if (!matrix[0] || !matrix[1] || !matrix[2])
		return ;
	x
		= vector->x * matrix[0]->x
		+ vector->y * matrix[0]->y
		+ vector->z * matrix[0]->z;
	y
		= vector->x * matrix[1]->x
		+ vector->y * matrix[1]->y
		+ vector->z * matrix[1]->z;
	z
		= vector->x * matrix[2]->x
		+ vector->y * matrix[2]->y
		+ vector->z * matrix[2]->z;
	vector->x = x;
	vector->y = y;
	vector->z = z;
}

t_vector	*ft_vectornormal(t_vector *first, t_vector *second)
{
	t_vector	**scale_matrix;
	t_vector	*normal;
	float		length;

	if (!first || !second)
		return (0);
	normal = ft_vectornew(second->x, second->y, 0);
	ft_vectorsubtract(normal, first);
	length = sqrt(pow(normal->x, 2) + pow(normal->y, 2));
	if (!length)
		return (0);
	scale_matrix = ft_matrix_scale_new(1.f / length);
	if (!scale_matrix)
		return (0);
	ft_vectormultiply(normal, scale_matrix);
	normal->z = length;
	ft_free_array((void **)scale_matrix);
	return (normal);
}
