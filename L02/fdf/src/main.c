/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/08/21 17:41:15 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int get_color(int z_value)
{
	if(z_value > 0)
	{
		return (0x00FFCC66);
	}
	return (0x00FF0000);
}
void draw_points(int **matrix, t_data *img, int row, int col)
{
	xy_data offset;
	xy_data dest;
	int i;
	int j;
	float a;

	offset.x = WINDOW_WIDTH / 2;
	offset.y = WINDOW_HEIGHT / 2;

	a = atan(1 / sqrt(2));
	i = 0;
	print_matrix(matrix, 11, 19);


	while(i < row)
	{
		j = 0;
		 while (j < col)
        {
            dest.x = (j - i) * cos(a) * BLOCK_SIZE;
            dest.y = ((i + j) * sin(a) - matrix[i][j]) * BLOCK_SIZE;

            dest.x = (offset.x + dest.x);
            dest.y = offset.y + dest.y;

			ft_printf("dest x: %d\n", (int)dest.x);
			ft_printf("dest y: %d\n", (int)dest.y);

            if (dest.x >= 0 && dest.x < WINDOW_WIDTH && dest.y >= 0 && dest.y < WINDOW_HEIGHT)
            {
                my_mlx_pixel_put(img, dest.x, dest.y, get_color(matrix[i][j]));
            }

            j++;
        }
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		fd;
	char	*file_path;

	// parsing map

	file_path = ft_strjoin("test_maps/", argv[1]);
	fd = open(file_path, O_RDONLY);
	int **matrix = parse_map(fd);


	// this is where im prting things out.
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	//this also needs to be number of rows in the matrix right ow its setto 42.fdf
	draw_points(matrix, &img, 11 , 19);

	// for (int i = 0; i < 100; i++)
	// {
	// 	for (int j = 0; j < 100; j++)
	// 		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	// }

	// my_mlx_pixel_put(&img, 900, 500, 0x00FF0000);
	sleep(1);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	// puts("test");
	return (0);
}
