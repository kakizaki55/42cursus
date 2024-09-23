/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:23:59 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/23 18:17:50 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	calculate_dest(t_vars *vars, xy_data *dest, int i, int j)
{
	dest->x = (j - i) * cos(vars->a) * vars->block_size;
	dest->y = ((i + j) * sin(vars->a) - (vars->matrix[i][j])
			/ vars->height_offest) * vars->block_size;
	dest->x = vars->offset.x + dest->x;
	dest->y = vars->offset.y + dest->y;
}

void	calculate_above(t_vars *vars, xy_data *above, int i, int j)
{
	above->x = (j - i + 1) * cos(vars->a) * vars->block_size;
	above->y = ((i + j - 1) * sin(vars->a) - (vars->matrix[i - 1][j])
			/ vars->height_offest) * vars->block_size;
	above->x = vars->offset.x + above->x;
	above->y = vars->offset.y + above->y;
}

void	reset_rows(int *j, xy_data *prev)
{
	*j = 0;
	prev->x = 0;
	prev->y = 0;
	return ;
}

void	reset_prev(xy_data *prev, xy_data *dest)
{
	prev->x = dest->x;
	prev->y = dest->y;
}
