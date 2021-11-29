/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:39:11 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 10:58:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_get_scale(int x, int y, int z)
{
	float	scale;

	if (!x || !z)
		return (0);
	scale = 1.2f;
	return ((ft_smallest(DISPLAY_X, DISPLAY_Y) / ft_biggest(x, y, z)) / 2);
}

int	ft_biggest(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (c);
	}
}

int	ft_smallest(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
