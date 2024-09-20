/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/20 19:30:47 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//reminder to uncomment CFLAGS in Makefile

void init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if(vars->mlx == NULL)
		exit(EXIT_FAILURE);
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF!");
	if(vars->win == NULL)
		exit(EXIT_FAILURE);
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if(vars->img == NULL)
		exit(EXIT_FAILURE);
	// vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
	// 	&vars->endian);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if(vars->addr == NULL)
		exit(EXIT_FAILURE);
}


int	main(int argc, char *argv[])
{
	t_vars 	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	if(vars == NULL)
		return(EXIT_FAILURE);

	parse_map(argv[1], vars);
	init_mlx(vars);
	draw_points(vars);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	init_hooks(vars);
	mlx_loop(vars->mlx);

	puts("does it actually make it here?");
	return (0);
}
