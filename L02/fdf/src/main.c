/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/10 14:08:40 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	// if(data->img == NULL);
	// 	return ;
	// printf("x:%d\n", x);
	// printf("y:%d\n", y);
	// printf("color:%x\n", color);
	// print_img(*data);

	dst = NULL;
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;

	}

}

//reminder to uncomment CFLAGS in Makefile

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	m_data 	data;
	int		fd;

	// parsing map

	parse_map(argv[1], &data);

	print_matrix(data.matrix, data.col, data.row);
	ft_printf("row:%d\n", data.row);
	ft_printf("col:%d\n", data.col);


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	//this also needs to be number of rows in the matrix right ow its set to 42.fdf

	// ft_printf("arr_length %d\n", int_arr_length((int *)matrix[0]));
	print_matrix(data.matrix, data.col, data.row);
	ft_printf("row:%d\n", data.row);
	ft_printf("col:%d\n", data.col);
	draw_points(data.matrix, &img, data.row , data.col);

	// my_mlx_pixel_put(&img, 900, 500, 0x00FF0000);
	sleep(1);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	// puts("test");
	return (0);
}
