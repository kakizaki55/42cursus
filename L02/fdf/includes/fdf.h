/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/08/21 16:42:07 by mkakizak         ###   ########.fr       */
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

#define TRUE 1
#define FALSE 0
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define BLOCK_SIZE 30;


//utils.c
void 	print_img(t_data img);
void 	print_matrix(int **matrix, int rows, int cols);
void	free_all(char **str);

//parse_map.c
int **parse_map(int fd);




#endif