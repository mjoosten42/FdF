/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:18:41 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/06 15:10:06 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_line(int fd)
{
	char	c;
	char	*str;
	int		len;

	len = 0;
	while (read(fd, &c, 1) > 0)
	{
		len++;
		if (c == '\n')
			break ;
	}
	if (!len || lseek(fd, -len, SEEK_CUR) < 0)
		return (0);
	str = malloc(len + 1);
	if (!str)
		return (0);
	if (read(fd, str, len) < 0)
	{
		free(str);
		return (0);
	}
	str[len] = 0;
	return (str);
}
