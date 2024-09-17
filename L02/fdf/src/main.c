/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/17 12:27:11 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//reminder to uncomment CFLAGS in Makefile

	void init_mlx(t_vars *vars)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (vars == NULL)
			return ;
		vars->mlx = mlx_init();
		if(vars->mlx == NULL)
			exit(EXIT_FAILURE);
		vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF!");
		if(vars->win == NULL)
			exit(EXIT_FAILURE);
		vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		if(vars->img == NULL)
			exit(EXIT_FAILURE);
		vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
			&vars->endian);
		if(vars->addr == NULL)
			exit(EXIT_FAILURE);
		// need to add error handling
	}
int	main(int argc, char *argv[])
{
	m_data 	*data;
	t_vars 	*vars;


	// parsing map

	data = (m_data *)ft_calloc(sizeof(m_data *), 1);
	if(data == NULL)
		return (NULL);

	parse_map(argv[1], data);
	print_matrix(data->matrix, data->col, data->row);
	ft_printf("row:%d\n", data->row);
	ft_printf("col:%d\n", data->col);


	vars = (t_vars *)ft_calloc(sizeof(t_vars *), 1);
	if(vars == NULL)
		return NULL;
	init_mlx(vars);
	//this also needs to be number of rows in the matrix right ow its set to 42.fdf

	// ft_printf("arr_length %d\n", int_arr_length((int *)matrix[0]));
	// print_matrix(data.matrix, data.col, data.row);
	// ft_printf("row:%d\n", data.row);
	// ft_printf("col:%d\n", data.col);

	// draw_points(data.matrix, &vars->img, data.row , data.col);

	// draw_points(data, vars);

	// dprintf(STDERR_FILENO, "begin check segv\n");
	// dprintf(STDERR_FILENO, "end check segv\n");

	// my_mlx_pixel_put(&img, 900, 500, 0x00FF0000);
	// sleep(1);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);


	init_hooks(vars);

	// mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, close_window, vars);
	// mlx_hook(vars->win, ON_DESTROY, 1L << 17, close_window, vars);
	// free(vars->mlx);
	// free(vars->win);
	// free(vars->img);
	// free(vars->addr);
	mlx_loop(vars->mlx);

	// free(vars);
	// puts("test");
	return (0);
}
