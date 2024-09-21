/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:27:44 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/21 17:09:15 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int close_window(t_vars *vars)
{

	// if (vars == NULL || vars->mlx == NULL || vars->win == NULL ||vars->img == NULL)
	// {
	// 	printf("checking to see if close works");
	// }
	distroy_and_exit(vars, EXIT_SUCCESS);
	// exit(EXIT_SUCCESS);
	return(0);
}

int key_hooks(int key, t_vars *vars)
{
	// if (vars == NULL || vars->mlx == NULL || vars->win == NULL ||vars->img == NULL)
	// {
	// 	printf("checking to see if close works");
	// }
	if(key == ESC)
	{
		distroy_and_exit(vars, EXIT_SUCCESS);
	}
	if(key == A)
		vars->offset.x += 10;
	if(key == W)
		vars->offset.y += 10;
	if(key == D)
		vars->offset.x -= 10;
	if(key == S)
		vars->offset.y -= 10;
	
	// printf("keys is: %d", key); fflush(stdout);
	return(0);
}

int	render_next_frame(t_vars *vars)
{
	// puts("this should come out in the console");
	// if(vars && vars->img)
    // 	mlx_destroy_image(vars->mlx, vars->img);
	// vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// if(vars->img == NULL)
	// 	exit(EXIT_FAILURE);
	// ft_printf("offset X/Y: %d\n", vars->offset); fflush(stdout);
	draw_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

int move_hook(int key, t_vars *vars)
{
	int mouse_event;
	printf("mouse code: %d", key); fflush(stdout);
}

void init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_hooks, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 17, close_window, vars);
	// mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, move_hook, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
}