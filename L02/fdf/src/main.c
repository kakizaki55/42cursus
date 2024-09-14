/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/14 16:52:43 by mkakizak         ###   ########.fr       */
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


typedef struct s_vars
{
	void 	*mlx;
	void 	*win;
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_vars;

int close_window(int keycode, t_vars *vars)
{	

	if (vars == NULL || vars->mlx == NULL || vars->win == NULL ||vars->img == NULL) 
	{
		printf("checking to see if close works");
	}
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img);
		free(vars);
		exit(EXIT_SUCCESS);
	return(0);
}

//reminder to uncomment CFLAGS in Makefile

	void init_mlx(t_vars *vars)
	{
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF!");
		vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
			&vars->endian);
		// need to add error handling
	}
int	main(int argc, char *argv[])
{
	m_data 	data;
	t_vars 	*vars;


	// parsing map

	parse_map(argv[1], &data);

	print_matrix(data.matrix, data.col, data.row);
	ft_printf("row:%d\n", data.row);
	ft_printf("col:%d\n", data.col);

	init_mlx(vars);

	//this also needs to be number of rows in the matrix right ow its set to 42.fdf

	// ft_printf("arr_length %d\n", int_arr_length((int *)matrix[0]));
	// print_matrix(data.matrix, data.col, data.row);
	// ft_printf("row:%d\n", data.row);
	// ft_printf("col:%d\n", data.col);

	draw_points(data.matrix, &vars->img, data.row , data.col);

	// my_mlx_pixel_put(&img, 900, 500, 0x00FF0000);
	sleep(1);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, ON_DESTROY, 1L << 17, close_window, vars);

	mlx_loop(vars->mlx);
	// puts("test");
	return (0);
}
