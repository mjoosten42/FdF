/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:31:59 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/22 14:31:10 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_create_frame(t_frame *frame, char *file)
{
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (ft_get_width(frame, fd))
		return (1);
	close(fd);
	fd = open(file, O_RDONLY);
	if (ft_get_heigth(frame, fd))
		return (2);
	close(fd);
	if (!(frame->width || frame->height))
		return (3);
	fd = open(file, O_RDONLY);
	ret = ft_file_to_points(fd, frame);
	close(fd);
	if (ret)
		return (4);
	if (!frame->points)
		return (5);
	return (0);
}

int	ft_get_width(t_frame *frame, int fd)
{
	char	*str;

	str = ft_get_next_line(fd);
	if (!str)
		return (1);
	frame->width = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		frame->width++;
		while (*str != ' ' && *str)
			str++;
	}
	return (0);
}

int	ft_get_heigth(t_frame *frame, int fd)
{
	char	*str;

	str = ft_get_next_line(fd);
	if (!str)
		return (1);
	frame->height = 0;
	while (str)
	{
		frame->height++;
		free(str);
		str = ft_get_next_line(fd);
	}
	return (0);
}

int	ft_file_to_points(int fd, t_frame *frame)
{
	char	*str;
	int		i;

	frame->points = malloc(sizeof(int) * frame->width * frame->height);
	if (!frame->points)
		return (1);
	i = 0;
	while (i < frame->height)
	{
		str = ft_get_next_line(fd);
		if (ft_str_to_points(str, frame, i))
			return (1);
		free(str);
		i++;
	}
	return (0);
}

int	ft_str_to_points(char *str, t_frame *frame, int row)
{
	char	**strs;
	int		i;

	strs = ft_split(str, ' ');
	if (!strs)
		return (1);
	i = 0;
	while (strs[i])
	{
		*(frame->points + i + row * frame->width) = ft_atoi(strs[i]);
		i++;
	}
	ft_free_strs(strs);
	return (0);
}
