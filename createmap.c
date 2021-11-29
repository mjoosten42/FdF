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
	int			points;

	points = ft_get_points(file);
	map = malloc(sizeof(*map) * (points + 1));
	if (!map)
		return (0);
	map[points] = 0;
	if (ft_fill_map(map, file))
	{
		ft_free_array((void **)map);
		return (0);
	}
	return (map);
}

int	ft_get_points(char *file)
{
	char	**strs;
	char	*str;
	int		fd;
	int		columns;
	int		rows;

	columns = 0;
	fd = open(file, O_RDONLY);
	str = ft_get_next_line(fd);
	strs = ft_split(str, ' ');
	if (strs)
	{
		while (strs[columns])
			columns++;
		ft_free_array((void **)strs);
	}
	rows = 0;
	while (str)
	{
		rows++;
		free(str);
		str = ft_get_next_line(fd);
	}
	close(fd);
	return (columns * rows);
}

int	ft_fill_map(t_vector **map, char *file)
{
	char	*str;
	int		fd;
	int		z;

	z = 0;
	fd = open(file, O_RDONLY);
	str = ft_get_next_line(fd);
	while (str)
	{
		map = ft_fill_row(map, str, z);
		if (!map)
		{
			free(str);
			close(fd);
			return (1);
		}
		free(str);
		str = ft_get_next_line(fd);
		z++;
	}
	close(fd);
	return (0);
}

t_vector	**ft_fill_row(t_vector **map, char *str, int z)
{
	t_vector	*vector;
	char		**strs;
	int			x;

	strs = ft_split(str, ' ');
	if (!strs)
		return (0);
	x = 0;
	while (strs[x])
	{
		*map = malloc(sizeof(*vector));
		if (!(*map))
		{
			ft_free_array((void **)strs);
			return (0);
		}
		(*map)->x = x;
		(*map)->y = ft_atoi(strs[x]);
		(*map)->z = z;
		(*map)->height = (*map)->y;
		map++;
		x++;
	}
	ft_free_array((void **)strs);
	return (map);
}
