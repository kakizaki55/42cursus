/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:09:18 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/20 21:06:46 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fdf.h>

void distroy_vars(t_vars *vars)
{
    if(vars && vars->img)
        mlx_destroy_image(vars->mlx, vars->img);
    if(vars && vars->win)
	    mlx_destroy_window(vars->mlx, vars->win);
    if(vars && vars->mlx)
	    mlx_destroy_display(vars->mlx);
    if(vars && vars->matrix)
	    free_matrix(vars->matrix);
	free(vars->mlx);
	free(vars);
    return ;
}

void distroy_and_exit(t_vars *vars, int error_code)
{
    distroy_vars(vars);
    exit(error_code);
}

void	free_matrix(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}