/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:27:44 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/14 20:37:48 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int close_window(t_vars *vars)
{	

	// if(key == NULL)
	
	if (vars == NULL || vars->mlx == NULL || vars->win == NULL ||vars->img == NULL) 
	{
		printf("checking to see if close works");
	}

		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		clean_up_vars(vars);
		exit(EXIT_SUCCESS);
	return(0);
}

int close_window_with_key(int key, t_vars *vars)
{	
	//# define ESC 65307
	if (vars == NULL || vars->mlx == NULL || vars->win == NULL ||vars->img == NULL) 
	{
		printf("checking to see if close works");
	}
	if(key == ESC)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		clean_up_vars(vars);
		exit(EXIT_SUCCESS);
	
	}
		// this free() shoulld probaly take care of all the pointerins
	return(0);
}

void init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, close_window_with_key, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 17, close_window, vars);
}