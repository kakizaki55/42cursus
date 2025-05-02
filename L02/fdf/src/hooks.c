/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:27:44 by mkakizak          #+#    #+#             */
/*   Updated: 2025/02/14 17:31:56 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	close_window(t_vars *vars)
{
	distroy_and_exit(vars, EXIT_SUCCESS, NULL);
	return (0);
}

static void	camera_controls(int key, t_vars *vars)
{
	if (key == A)
		vars->offset.x += 10;
	if (key == W)
		vars->offset.y += 10;
	if (key == D)
		vars->offset.x -= 10;
	if (key == S)
		vars->offset.y -= 10;
}

static void	zoom_controls(int key, t_vars *vars)
{
	if (key == UP && vars->block_size < INT_MAX)
	{
		vars->block_size += 1;
		vars->offset.x -= 5;
		vars->offset.y -= 5;
	}
	if (key == DOWN && vars->block_size > 1)
	{
		vars->block_size -= 1;
		vars->offset.x += 5;
		vars->offset.y += 5;
	}
}

static void	angle_controls(int key, t_vars *vars)
{
	if (key == LEFT && vars->a < .5)
	{
		vars->a += .01;
	}
	if (key == RIGHT && vars->a > 0)
	{
		vars->a -= .01;
	}
}

int	key_hooks(int key, t_vars *vars)
{
	if (key == ESC)
	{
		distroy_and_exit(vars, EXIT_SUCCESS, NULL);
	}
	camera_controls(key, vars);
	zoom_controls(key, vars);
	angle_controls(key, vars);
	return (0);
}
