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
void draw_points(int **matrix, t_data *img)
{
	my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
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
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); fflush(stdout);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	draw_points(matrix, &img);

	// for (int i = 0; i < 100; i++)
	// {
	// 	for (int j = 0; j < 100; j++)
	// 		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	// }

	my_mlx_pixel_put(&img, 900, 500, 0x00FF0000);
	sleep(1);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	// puts("test");
	return (0);
}
