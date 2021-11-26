/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/26 15:30:50 by mjoosten         ###   ########.fr       */
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

typedef struct s_frame
{
	int		*points;
	int		height;
	int		width;
}		t_frame;

typedef struct s_window
{
	void	*mlx;
	void	*win;

	void	*img;
	int		*buf;

	t_frame	*frame;

	float	scale;
}			t_window;

int			ft_close(t_window *window);

t_window	*ft_create_window(char *file);
int			*ft_get_buffer(void *img);
void		*ft_window_error(t_window *window, int error);

t_frame		*ft_create_frame(char *file);
int			ft_get_width(int fd);
int			ft_get_heigth(int fd);
int			*ft_get_points(int fd, int width, int height);
int			ft_points_copy(char *str, int *points);
float		ft_get_scale(int width, int height);

void		ft_frame_to_image(t_window *window);

int			ft_key_hook(int keycode, t_window *window);
int			ft_get_pixel(t_window *window, int x, int y);

#endif