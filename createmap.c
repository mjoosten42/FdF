/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:59:06 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 12:08:45 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	**ft_create_map(char *file)
{
	t_vector	**map;
	int			width;
	int			height;

	width = ft_get_width(file);
	height = ft_get_height(file);
	map = malloc(sizeof(*map) * (width * height + 1));
	if (!map)
		ft_error(0);
	map[width * height] = 0;
	ft_fill_map(map, file);
	return (map);
}

int	ft_get_width(char *file)
{
	char	**strs;
	char	*str;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(0);
	str = ft_get_next_line(fd);
	strs = ft_split(str, ' ');
	if (!strs)
		ft_error(0);
	i = 0;
	while (strs[i])
		i++;
	ft_free_array((void **)strs);
	free(str);
	close(fd);
	return (i);
}

int	ft_get_height(char *file)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(0);
	str = ft_get_next_line(fd);
	i = 0;
	while (str)
	{
		free(str);
		i++;
		str = ft_get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_fill_map(t_vector **map, char *file)
{
	char	*str;
	int		fd;
	int		j;

	j = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(0);
	str = ft_get_next_line(fd);
	while (str)
	{
		map += ft_fill_row(map, str, j);
		free(str);
		str = ft_get_next_line(fd);
		j++;
	}
	close(fd);
	return (0);
}

int	ft_fill_row(t_vector **map, char *str, int j)
{
	char		**strs;
	int			i;

	strs = ft_split(str, ' ');
	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
	{
		map[i] = ft_vectornew(i, -ft_atoi(strs[i]), j);
		if (!map[i])
			ft_error(0);
		map[i]->height = -map[i]->y;
		i++;
	}
	ft_free_array((void **)strs);
	return (i);
}
