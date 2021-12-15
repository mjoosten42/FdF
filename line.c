/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:43:03 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 13:24:48 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_window *window, t_vector *first, t_vector *second)
{
	t_vector	*vector;
	t_vector	*normal;
	float		yhalf;

	if (fabs(first->x - second->x) <= 1 && fabs(first->y - second->y) <= 1)
		return ;
	vector = ft_vectornew(first->x, first->y, 0);
	vector->height = first->height;
	vector->x += 0.5f * DISPLAY_X;
	yhalf = 0.5f * DISPLAY_Y;
	normal = ft_vectornormal(first, second);
	if (!normal)
		return ;
	normal->height = (second->height - first->height) / normal->z;
	while ((int)normal->z--)
	{
		ft_pixel_put(window, vector->x, -vector->y + yhalf,
			BLUE << (int)(0.5f + window->gradient * vector->height));
		ft_vectoradd(vector, normal);
		vector->height += normal->height;
	}
	free(vector);
	free(normal);
}
