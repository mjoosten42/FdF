/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:02:53 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/25 16:25:39 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//frame->points[i * frame->width + j] << 20;

int	ft_frame_to_image(t_frame *frame, int *buffer)
{
	int		i;
	int		j;
	float	scale;

	scale = ft_get_scale(frame);
	i = 0;
	while (i < frame->height)
	{
		j = 0;
		while (j < frame->width)
		{
			buffer[DISPLAY_X * (int)(i * scale) + (int)(j * scale)] = frame->points[i * frame->width + j] << 20;
			if (frame->points[i * frame->width + j] == 0)
				buffer[DISPLAY_X * (int)(i * scale) + (int)(j * scale)] = WHITE;
			j++;
		}
		i++;
	}
	return (0);
}

float	ft_get_scale(t_frame *frame)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	scale = 1.2f;
	scale_x = (float)DISPLAY_X / (float)frame->width;
	scale_y = (float)DISPLAY_Y / (float)frame->height;
	if (scale_x < scale_y)
		return (scale_x / scale);
	return (scale_y / scale);
}
