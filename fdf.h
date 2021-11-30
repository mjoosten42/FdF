/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/30 15:47:59 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# define DISPLAY_X 1080
# define DISPLAY_Y 720

# define WHITE 0x00FFFFFF

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13

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
	int			width;
}			t_window;

t_window	*ft_create_window(char *file);
int			ft_get_width(char *file);

t_vector	**ft_create_map(char *file);
int			ft_get_points(char *file);
int			ft_fill_map(t_vector **map, char *file);
t_vector	**ft_fill_row(t_vector **map, char *str, int z);

t_vector	*ft_vectornew(int x, int y, int z);
void		ft_vectoradd(t_vector *vector, t_vector *move);
void		ft_vectorsubtract(t_vector *vector, t_vector *move);
void		ft_vectormultiply(t_vector *vector, t_vector **matrix);

t_vector	**ft_matrix_scale_new(float scale);
void		ft_fill_scale_matrix(t_vector **scale_matrix, float scale);

t_vector	**ft_matrix_rotate_new(char c, float angle);
void		ft_fill_rotate_x(t_vector **rotate_matrix, double radian);
void		ft_fill_rotate_y(t_vector **rotate_matrix, double radian);
void		ft_fill_rotate_z(t_vector **rotate_matrix, double radian);

void		ft_scale_map(t_vector **map, float scale);
float		ft_get_scale(t_vector **map);
void		ft_center_map(t_vector **map);
void		ft_rotate_map(t_vector **map, char c, float angle);
void		ft_draw_map(t_window *window);

void		ft_drawline(t_window *window, t_vector *first, t_vector *second);

t_vector	*ft_get_map_max(t_vector **map);
t_vector	*ft_get_map_min(t_vector **map);

int			ft_mouse_hook(int button, int x, int y, t_window *window);
int			ft_key_hook(int keycode, t_window *window);
int			ft_close(t_window *window);

#endif