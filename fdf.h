/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/06 15:33:27 by mjoosten         ###   ########.fr       */
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

# define A 0
# define S 1
# define D 2
# define Q 12
# define W 13
# define E 14
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
	int			width;
	int			height;
}			t_window;

void		printvector(t_vector *vector);
void		printmatrix(t_vector **matrix);

t_window	*ft_create_window(char *file);
t_vector	**ft_create_map(char *file);
int			ft_get_width(char *file);
int			ft_get_height(char *file);
int			ft_fill_map(t_vector **map, char *file);
int			ft_fill_row(t_vector **map, char *str, int j);

t_vector	*ft_vectornew(float x, float y, float z);
void		ft_vectoradd(t_vector *vector, t_vector *move);
void		ft_vectorsubtract(t_vector *vector, t_vector *move);
void		ft_vectormultiply(t_vector *vector, t_vector **matrix);

t_vector	**ft_matrix_scale_new(float scale);
t_vector	**ft_matrix_rotate_new(char c, float angle);
void		ft_fill_rotate_matrix(t_vector **matrix, char c, double radian);

void		ft_scale_map(t_vector **map, float scale);
float		ft_get_scale(t_vector **map);
t_vector	*ft_mapmax(t_vector **map);
void		ft_rotate_map(t_vector **map, char c, float angle);
void		ft_draw_map(t_window *window);

void		ft_drawline(t_window *window, t_vector *first, t_vector *second);
void		ft_boldline(t_window *window, float x, float y, int color);

int			ft_mouse_hook(int button, int x, int y, t_window *window);
int			ft_key_hook(int keycode, t_window *window);
int			ft_close(t_window *window);

#endif