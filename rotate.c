/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:49 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/30 13:01:19 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	**ft_matrix_rotate_new(char c, float angle)
{
	t_vector	**rotate_matrix;

	rotate_matrix = malloc(sizeof(*rotate_matrix) * 4);
	rotate_matrix[0] = malloc(sizeof(t_vector));
	rotate_matrix[1] = malloc(sizeof(t_vector));
	rotate_matrix[2] = malloc(sizeof(t_vector));
	rotate_matrix[3] = 0;
	if (!(rotate_matrix[0] && rotate_matrix[1] && rotate_matrix[2]))
	{
		free(rotate_matrix[0]);
		free(rotate_matrix[1]);
		free(rotate_matrix[2]);
		free(rotate_matrix);
		return (0);
	}
	if (c == 'x')
		ft_fill_rotate_x(rotate_matrix, angle);
	if (c == 'y')
		ft_fill_rotate_y(rotate_matrix, angle);
	if (c == 'z')
		ft_fill_rotate_z(rotate_matrix, angle);
	return (rotate_matrix);
}

void	ft_fill_rotate_x(t_vector **rotate_matrix, float angle)
{
	double	radian;

	radian = angle / (2 * M_PI);
	rotate_matrix[0]->x = 1;
	rotate_matrix[0]->y = 0;
	rotate_matrix[0]->z = 0;
	rotate_matrix[1]->x = 0;
	rotate_matrix[1]->y = cos(radian);
	rotate_matrix[1]->z = -sin(radian);
	rotate_matrix[2]->x = 0;
	rotate_matrix[2]->y = sin(radian);
	rotate_matrix[2]->z = cos(radian);
}

void	ft_fill_rotate_y(t_vector **rotate_matrix, float angle)
{
	double	radian;

	radian = angle / (2 * M_PI);
	rotate_matrix[0]->x = cos(radian);
	rotate_matrix[0]->y = 0;
	rotate_matrix[0]->z = sin(radian);
	rotate_matrix[1]->x = 0;
	rotate_matrix[1]->y = 1;
	rotate_matrix[1]->z = 0;
	rotate_matrix[2]->x = -sin(radian);
	rotate_matrix[2]->y = 0;
	rotate_matrix[2]->z = cos(radian);
}

void	ft_fill_rotate_z(t_vector **rotate_matrix, float angle)
{
	double	radian;

	radian = angle / (2 * M_PI);
	rotate_matrix[0]->x = cos(radian);
	rotate_matrix[0]->y = -sin(radian);
	rotate_matrix[0]->z = 0;
	rotate_matrix[1]->x = sin(radian);
	rotate_matrix[1]->y = cos(radian);
	rotate_matrix[1]->z = 0;
	rotate_matrix[2]->x = 0;
	rotate_matrix[2]->y = 0;
	rotate_matrix[2]->z = 1;
}
