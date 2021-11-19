/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/19 16:38:50 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

# include <unistd.h>
# include <stdio.h>

# define DISPLAY_X 1080
# define DISPLAY_Y 720

# define DEPTH 4
# define WHITE 0x00FFFFFF

typedef struct s_window
{
	void	*mlx;
	void	*win;
}			t_window;

int		ft_create_window(t_window *window);
int		ft_hooks(t_window *window);
int		ft_key_hook(int keycode, t_window *window);
int		ft_close(t_window *window);

void	*ft_create_image(t_window *window);

#endif