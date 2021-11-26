/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:39:11 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/26 16:39:31 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_width(char *file)
{
	char	*str;
	char	*start;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	str = ft_get_next_line(fd);
	if (!str)
		close(fd);
	if (!str)
		return (0);
	start = str;
	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		i++;
		while (*str != ' ' && *str)
			str++;
	}
	free(start);
	close(fd);
	return (i);
}

int	ft_get_height(char *file)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	str = ft_get_next_line(fd);
	i = 0;
	while (str)
	{
		i++;
		free(str);
		str = ft_get_next_line(fd);
	}
	close(fd);
	return (i);
}

float	ft_get_scale(int width, int height)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	if (!(width && height))
		return (0);
	scale = 1.2f;
	scale_x = (float)DISPLAY_X / (float)width;
	scale_y = (float)DISPLAY_Y / (float)height;
	if (scale_x < scale_y)
		return (scale_x / scale);
	return (scale_y / scale);
}
