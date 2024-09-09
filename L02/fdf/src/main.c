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

// need to figure out how this function works.....

void draw_line(xy_data point1, xy_data point2, int height, t_data *img)
{

    int x0 = point1.x, y0 = point1.y;
    int x1 = point2.x, y1 = point2.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        my_mlx_pixel_put(img, x0, y0, get_color(height));
        if (x0 == x1 && y0 == y1) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
	return ;
}



void draw_points(int **matrix, t_data *img, int row, int col)
{
	xy_data offset;
	xy_data dest;
	int i;
	int j;
	float a;
	xy_data vert = { NULL, NULL };
	xy_data hor = { NULL, NULL };

	offset.x = WINDOW_WIDTH / 2;
	offset.y = WINDOW_HEIGHT / 3;

	a = atan(1 / sqrt(2));
	// printf("a:%f\n", a);
	i = 0;
	// print_matrix(matrix, 11, 19);
	// ft_printf("length:%d\n" , str_arr_length((int *)matrix[1]));

	while(i < row)
	{
		j = 0;
		vert.x = NULL;
		vert.y = NULL;
		// col = str_arr_length(matrix[i]);
		// ft_printf("col:%d\n",col);

		while(j < col)
        {
			//what the hell is this?
            dest.x = (j - i) * cos(a) * BLOCK_SIZE;
            dest.y = ((i + j) * sin(a) - (matrix[i][j]) / HEIGHT_OFFSET ) * BLOCK_SIZE;

            dest.x = offset.x + dest.x;
            dest.y = offset.y + dest.y;

			// ft_printf("dest x: %d\n", (int)dest.x);
			// ft_printf("dest y: %d\n", (int)dest.y);
			if(i > 0)
			{
				//and this?
				hor.x = (j - i + 1) * cos(a) * BLOCK_SIZE;
            	hor.y = ((i + j - 1) * sin(a) - (matrix[i -1][j]) / HEIGHT_OFFSET) * BLOCK_SIZE;
				hor.x = offset.x + hor.x;
				hor.y = offset.y + hor.y;
				draw_line(hor, dest, 0, img);
			}

			if(vert.x || vert.y)
				draw_line(vert, dest, 0, img);

			vert.x = dest.x;
			vert.y = dest.y;

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
	draw_points(data.matrix, &img, data.col , data.row);

	// my_mlx_pixel_put(&img, 900, 500, 0x00FF0000);
	sleep(1);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	// puts("test");
	return (0);
}
