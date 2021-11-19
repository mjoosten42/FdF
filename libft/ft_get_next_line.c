/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:18:41 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/16 12:37:55 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_line(int fd)
{
	char	c;
	char	*str;
	int		len;

	if (read(fd, &c, 0) < 0)
		return (0);
	len = 0;
	while (read(fd, &c, 1) > 0)
	{
		len++;
		if (c == '\n')
			break ;
	}
	if (lseek(fd, -len, SEEK_CUR) < 0 || !len)
		return (0);
	str = malloc(len + 1);
	if (!str)
		return (0);
	read(fd, str, len);
	str[len] = 0;
	return (str);
}
