/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/29 15:38:15 by mjoosten         ###   ########.fr       */
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
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;

	int		height;
}			t_vector;

typedef struct s_window
{
	void		*mlx;
	void		*win;

	t_vector	**map;
}			t_window;

t_window	*ft_create_window(char *file);

t_vector	**ft_create_map(char *file);
int			ft_get_points(char *file);
int			ft_fill_map(t_vector **map, char *file);
t_vector	**ft_fill_row(t_vector **map, char *str, int z);

void		ft_matrix_add(t_vector **map, t_vector *vector);
void		ft_matrix_multiply(t_vector *scale, t_vector **matrix);

t_vector	*ft_create_move_matrix(int x, int y, int z);
t_vector	**ft_create_scale_matrix(float scale);

void		ft_scale_map(t_vector **map, float scale);
void		ft_center_map(t_vector **map);
float		ft_get_scale(t_vector **map);
t_vector	*ft_base_map(t_vector **map);
void		ft_vector_invert(t_vector *vector);

float		ft_get_x_max(t_vector **map);
float		ft_get_x_min(t_vector **map);
float		ft_get_y_max(t_vector **map);
float		ft_get_y_min(t_vector **map);
float		ft_get_z_max(t_vector **map);
float		ft_get_z_min(t_vector **map);

void		ft_draw_map(t_window *window);
int			ft_mouse_hook(int button, int x, int y, t_window *window);
int			ft_key_hook(int keycode, t_window *window);
int			ft_close(t_window *window);

#endif