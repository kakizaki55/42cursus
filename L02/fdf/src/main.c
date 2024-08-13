/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/08/01 19:45:27 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char *argv[])
{
	// int		fd;
	// char	*file_path;
	// int		bool;
	// char	*str;


	void	*mlx;
	void	*mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img =  mlx_new_image(mlx, 1920, 1080);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	mlx_pixel_put(&img, mlx_win, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);


	// if (argc != 2)
	// 	return (1);
	// file_path = ft_strjoin("test_maps/", argv[1]);
	// fd = open(file_path, O_RDONLY);
	// bool = TRUE;
	// for (int i = 0; bool; i++)
	// {
	// 	str = get_next_line(fd);
	// 	if (str)
	// 		ft_printf("%s\n", str);
	// 	else
	// 		bool = FALSE;
	// }
	// ft_printf("hello there just checking\n");
	return (0);
}
