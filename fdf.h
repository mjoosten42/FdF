/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/26 16:31:47 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

# include <stdio.h>

# define DISPLAY_X 1080
# define DISPLAY_Y 720

# define WHITE 0x00FFFFFF

# define ESC 53

typedef struct s_window
{
	void	*mlx;
	void	*win;

	void	*img;
	int		*buf;

	int		width;
	int		height;
	float	scale;
}			t_window;

int			ft_close(t_window *window);

t_window	*ft_create_window(char *file);
int			*ft_get_buffer(void *img);
int			ft_get_width(char *file);
int			ft_get_height(char *file);
float		ft_get_scale(int width, int height);
void		ft_window_init(t_window *window);

int			ft_key_hook(int keycode, t_window *window);

void		ft_draw_points(t_window *window, char *file);
int			ft_draw_row(t_window *window, char *str, int row);

#endif