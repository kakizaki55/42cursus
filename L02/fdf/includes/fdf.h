/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/10 13:24:04 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct point_data {
	int	x;
	int y;
	int z;
	int color;
}				p_data;

typedef struct xy_data {
	int x;
	int y;
} 				xy_data;

typedef struct m_data {
	int **matrix;
	int row;
	int col;
}				m_data;

#define TRUE 1
#define FALSE 0
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define BLOCK_SIZE 30
#define HEIGHT_OFFSET 1


//utils.c
void 	print_img(t_data img);
void 	print_matrix(int **matrix, int rows, int cols);
void	free_all(char **str);
int 	get_color(int z_value);
int 	str_arr_length(char **array);
int 	int_arr_length(int *array);

//parse_map.c
void parse_map(char *file_path, m_data *data);
int get_file_length(char *file_path);

//draw.c
void draw_points(int **matrix, t_data *img, int row_len, int col_len);
void draw_line(xy_data point1, xy_data point2, int z_value, t_data *img);





#endif