/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:43:03 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/11 16:23:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_vertical(t_window *window, t_vector *first, t_vector *second);
int		ft_neighbours(t_vector *first, t_vector *second);

void	ft_drawline(t_window *window, t_vector *first, t_vector *second)
{
	float	x;
	float	y;
	float	xhalf;
	float	yhalf;
	float	slope;
	int		height;

	if (ft_neighbours(first, second))
		return ;
	if (first->x > second->x)
	{
		ft_drawline(window, second, first);
		return ;
	}
	slope = 0;
	if (first->x != second->x)
		slope = (second->y - first->y) / (second->x - first->x);
	else
		ft_draw_vertical(window, first, second);
	xhalf = 0.5f * DISPLAY_X;
	yhalf = 0.5f * DISPLAY_Y;
	x = first->x;
	y = first->y;
	height = first->height;
	if (slope > 1)
	{
		slope = 1.f / slope;
		while (y < second->y)
		{
			mlx_pixel_put(window->mlx, window->win,
				x + xhalf,
				y + yhalf,
				BLUE + height++);
			x += slope;
			y++;
		}
		return ;
	}
	if (slope < -1)
	{
		slope = 1.f / slope;
		while (y > second->y)
		{
			mlx_pixel_put(window->mlx, window->win,
				x + xhalf,
				y + yhalf,
				BLUE + height++);
			x -= slope;
			y--;
		}
		return ;
	}
	while (x < second->x)
	{
		mlx_pixel_put(window->mlx, window->win,
			x + xhalf,
			y + yhalf,
			BLUE + height++);
		y += slope;
		x++;
	}
}

void	ft_draw_vertical(t_window *window, t_vector *first, t_vector *second)
{
	float	y;
	float	xhalf;
	float	yhalf;
	int		height;

	xhalf = 0.5f * DISPLAY_X;
	yhalf = 0.5f * DISPLAY_Y;
	y = first->y;
	height = first->height;
	y = first->y;
	if (y > second->y)
	{
		while (y > second->y)
		{
			mlx_pixel_put(window->mlx, window->win,
				first->x + xhalf,
				y + yhalf,
				BLUE + height++);
			y--;
		}
	}
	else
	{
		while (y < second->y)
		{
			mlx_pixel_put(window->mlx, window->win,
				first->x + 0.5f * (float)DISPLAY_X,
				y + 0.5f * (float)DISPLAY_Y,
				WHITE);
			y++;
		}	
	}
}

int	ft_neighbours(t_vector *first, t_vector *second)
{
	float	xdiff;
	float	ydiff;

	xdiff = first->x - second->x;
	ydiff = first->y - second->y;
	if (xdiff >= -1 && xdiff <= 1 && ydiff >= -1 && ydiff <= 1)
		return (1);
	return (0);
}
/*
void	ft_drawline(t_window *window, t_vector *first, t_vector *second)
{
	t_vector	*a;
	t_vector	*b;
	int			length;

	if (!(window && first && second))
		return ;
	a = ft_vectornew(first->x, first->y, 0);
	b = ft_vectornew(second->x, second->y, 0);
	if (!a || !b || (first->x == second->x && first->y == second->y))
	{
		free(a);
		free(b);
		return ;
	}
	ft_vectorsubtract(b, a);
	length = (int)ft_vectornormal(b);
	if (!length)
		return ;
	while (length--)
	{
		ft_vectoradd(a, b);
		mlx_pixel_put(window->mlx, window->win,
			a->x + 0.5f * (float)DISPLAY_X,
			a->y + 0.5f * (float)DISPLAY_Y,
			WHITE);
	}
	free(a);
	free(b);
}
*/