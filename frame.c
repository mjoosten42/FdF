/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:31:59 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/26 15:32:29 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_frame	*ft_create_frame(char *file)
{
	t_frame	*frame;
	int		fd;

	frame = malloc(sizeof(*frame));
	if (!frame)
		return (0);
	fd = open(file, O_RDONLY);
	frame->width = ft_get_width(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	frame->height = ft_get_heigth(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	frame->points = ft_get_points(fd, frame->width, frame->height);
	close(fd);
	if (!frame->width || !frame->height || !frame->points)
	{
		free(frame->points);
		free(frame);
		return (0);
	}
	return (frame);
}

int	ft_get_width(int fd)
{
	char	*str;
	char	*start;
	int		i;

	str = ft_get_next_line(fd);
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
	return (i);
}

int	ft_get_heigth(int fd)
{
	char	*str;
	int		i;

	str = ft_get_next_line(fd);
	i = 0;
	while (str)
	{
		i++;
		free(str);
		str = ft_get_next_line(fd);
	}
	return (i);
}

int	*ft_get_points(int fd, int width, int height)
{
	char	*str;
	int		*points;
	int		*start;

	if (!width || !height)
		return (0);
	points = malloc(sizeof(*points) * width * height);
	if (!points)
		return (0);
	start = points;
	str = ft_get_next_line(fd);
	while (str)
	{
		points += ft_points_copy(str, points);
		free(str);
		str = ft_get_next_line(fd);
	}
	return (start);
}

int	ft_points_copy(char *str, int *points)
{
	char	**strs;
	int		i;

	strs = ft_split(str, ' ');
	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
	{
		points[i] = ft_atoi(strs[i]);
		i++;
	}
	ft_free_strs(strs);
	return (i);
}
