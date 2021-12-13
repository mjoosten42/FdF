/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:42 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/13 16:02:17 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define DISPLAY_X 1080
# define DISPLAY_Y 720

# define BLUE 0x000000FF

# define ESC 53

# define LEFT_MOUSE_BUTTON 	1
# define SCROLL_UP 			4
# define SCROLL_DOWN 		5

# define BUTTON_RELEASE 5
# define MOTION_NOTIFY 	6
# define DESTROY_NOTIFY	17

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;

	float	height;
}			t_vector;

typedef struct s_window
{
	void		*mlx;
	void		*win;

	t_vector	**map;
	t_vector	*size;
	float		gradient;

	int			mouse;
	int			x;
	int			y;
}				t_window;

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
t_vector	*ft_vectornormal(t_vector *first, t_vector *second);

t_vector	**ft_matrix_scale_new(float scale);
float		ft_get_scale(t_window *window);
t_vector	**ft_matrix_rotate_new(char c, float angle);
void		ft_fill_rotate_matrix(t_vector **matrix, char c, double radian);

t_vector	*ft_mapsize(t_vector **map);
void		ft_center_map(t_vector **map, t_vector *max);
void		ft_scale_map(t_vector **map, float scale);
void		ft_rotate_map(t_vector **map, char c, float angle);
void		ft_draw_map(t_window *window);

void		ft_drawline(t_window *window, t_vector *first, t_vector *second);

int			ft_mouse_hook(int button, int x, int y, t_window *window);
int			ft_key_hook(int keycode, t_window *window);
int			ft_motion(int x, int y, t_window *window);
int			ft_release(int button, int x, int y, t_window *window);

int			ft_error(char *str);
int			ft_close(t_window *window);

#endif