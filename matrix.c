/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:59:06 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 11:18:51 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*ft_create_matrix(char *file)
{
	t_vector	*matrix;
	int			points;

	points = ft_get_points(file);
	matrix = malloc(sizeof(*matrix) * (points + 1));
	if (!matrix)
		return (0);
	matrix[points] = 0;
	ft_fill_matrix(matrix, points, file);
	}
}

int	ft_get_points(char *file)
{
	char	**strs;
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	str = ft_get_next_line(fd);
	strs = ft_split(str, ' ');
	if (strs)
	{
		while (strs[i])
			i++;
		free(strs);
	}
	while (str)
	{
		i += i;
		free(str);
		str = ft_get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_fill_matrix(t_vector *matrix, int points, char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY)
}