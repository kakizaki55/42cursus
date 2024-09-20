/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/21 00:03:47 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
typedef struct xy_data {
	int x;
	int y;
} 				xy_data;

typedef struct point_data {
	int	x;
	int y;
	int z;
	int color;
}				p_data;

typedef struct s_vars
{
	void 	*mlx;
	void 	*win;
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	**matrix;
	int 	row;
	int 	col;
	xy_data offset;
}				t_vars;


#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define BLOCK_SIZE 30
#define HEIGHT_OFFSET 1

typedef enum s_hooks
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ESC = 65307
}				t_hooks;

//utils.c
void 	print_img(t_vars vars);
void 	print_matrix(int **matrix, int rows, int cols);
void	free_all(char **str);
int 	get_color(int z_value);
int 	str_arr_length(char **array);
int 	int_arr_length(int *array);

//parse_map.c
void 	parse_map(char *file_path, t_vars *vars);
int 	get_file_length(char *file_path);

//draw.c
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void 	draw_points(t_vars *vars);
void 	draw_line(xy_data point1, xy_data point2, int z_value, t_vars *vars);

//cleanup.c
void 	distroy_vars(t_vars *vars);
void 	distroy_and_exit(t_vars *vars, int error_code);
void 	free_matrix(int **matrix);

//hooks.c
int		close_window(t_vars *vars);
int 	close_window_with_key(int key, t_vars *vars);
void 	init_hooks(t_vars *vars);


#endif