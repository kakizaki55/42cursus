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
