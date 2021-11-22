/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/22 16:33:17 by mjoosten         ###   ########.fr       */
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
	int	*points;
	int	height;
	int	width;
}		t_frame;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_window;

int		ft_create_window(t_window *window);
int		*ft_create_image(t_window *window);
int		ft_hooks(t_window *window);
int		ft_key_hook(int keycode, t_window *window);
int		ft_close(t_window *window);

int		ft_create_frame(t_frame *frame, char *file);
int		ft_get_width(t_frame *frame, int fd);
int		ft_get_heigth(t_frame *frame, int fd);
int		ft_file_to_points(t_frame *frame, int fd);
int		ft_str_to_points(char *str, t_frame *frame, int row);

void	ft_error(void);

#endif