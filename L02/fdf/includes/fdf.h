/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/23 18:40:43 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>

typedef struct t_xy_data
{
	int			x;
	int			y;
}				t_xy_data;

typedef struct t_color
{
	int			t;
	int			r;
	int			g;
	int			b;
}				t_c_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			**matrix;
	int			row;
	int			col;
	t_xy_data	offset;
	int			block_size;
	float		a;
	int			height_offest;
}				t_vars;

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

typedef enum s_hooks
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ESC = 65307,
	A = 97,
	W = 119,
	S = 115,
	D = 100,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
}				t_hooks;

// utils.c
void			print_matrix(int **matrix, int rows, int cols);
void			free_all(char **str);
int				str_arr_length(char **array);
int				int_arr_length(int *array);

// color.c
int				color_hex(int t, unsigned int r, unsigned int g,
					unsigned int b);
int				get_color(int z_value);

// parse_map.c
void			parse_map(char *file_path, t_vars *vars);
int				get_file_length(char *file_path);

// draw_utils.c
void			calculate_dest(t_vars *vars, t_xy_data *dest, int i, int j);
void			calculate_above(t_vars *vars, t_xy_data *above, int i, int j);
void			reset_rows(int *j, t_xy_data *prev);
// draw.c
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void			draw_points(t_vars *vars);
void			draw_line(t_xy_data point1, t_xy_data point2, int z_value,
					t_vars *vars);

// cleanup.c
void			distroy_vars(t_vars *vars);
void			distroy_and_exit(t_vars *vars, int error_code, char *message);
void			free_matrix(int **matrix);

// hooks.c
int				close_window(t_vars *vars);
int				key_hooks(int key, t_vars *vars);
void			init_hooks(t_vars *vars);

// introduction.c
void			print_menu(t_vars *vars);

#endif