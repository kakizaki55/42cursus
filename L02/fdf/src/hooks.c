/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:27:44 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/22 17:04:28 by minoka           ###   ########.fr       */
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
	//Camera movemnt
	if(key == A)
		vars->offset.x += 10;
	if(key == W)
		vars->offset.y += 10;
	if(key == D)
		vars->offset.x -= 10;
	if(key == S)
		vars->offset.y -= 10;
	// ZOOM controls
	if(key == UP && vars->block_size < INT_MAX)
	{
		vars->block_size += 1;
		vars->offset.x -= 3;
		vars->offset.y -= 3;
	}
	if(key == DOWN && vars->block_size > 1)
	{
		vars->block_size -= 1;
		vars->offset.x += 3;
		vars->offset.y += 3;
	}
	//Angle controls
	if(key == LEFT && vars->a < .5)
	{
		vars->a += .01;
	}
	if(key == RIGHT && vars->a > 0)
	{
		vars->a -= .01;
	}

	// printf("a is: %f", vars->a); fflush(stdout);
	return(0);
}

int	render_next_frame(t_vars *vars)
{
	if(vars && vars->img)
        mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if(vars->img == NULL)
		exit(EXIT_FAILURE);
	// ft_printf("offset X/Y: %d\n", vars->offset); fflush(stdout);
	// ft_printf("BLOCK_SIZE: %d\n", vars->block_size); fflush(stdout);
	draw_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

int mouse_hook(int button, int x, int y, t_vars *vars)
{
	int mouse_event;
	printf("mouse code: %d", button); fflush(stdout);
}

void init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_hooks, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 17, close_window, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 0, mouse_hook, vars);
	// mlx_hook(vars->win, ON_MOUSEDOWN, 0, mouse_move, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
}


// int	mouse_press(int button, int x, int y, void *param);

//
// int			mouse_press(int button, int x, int y, void *param)
// {move_hook
// 	t_fdf	*fdf;

// 	(void)x;
// 	(void)y;
// 	fdf = (t_fdf *)param;
// 	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
// 		zoom(button, fdf);
// 	else if (button == MOUSE_LEFT_BUTTON)
// 		fdf->mouse->is_pressed = true;
// 	return (0);
// }

// int			mouse_press(int button, int x, int y, void *param)
// {
// 	t_fdf	*fdf;

// 	(void)x;
// 	(void)y;
// 	fdf = (t_fdf *)param;
// 	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
// 		zoom(button, fdf);
// 	else if (button == MOUSE_LEFT_BUTTON)
// 		fdf->mouse->is_pressed = true;
// 	return (0);
// }
