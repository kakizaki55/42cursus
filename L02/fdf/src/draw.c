/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:22:17 by minoka            #+#    #+#             */
/*   Updated: 2024/09/22 19:57:43 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void init_steps(xy_data *dest, xy_data *step, xy_data *point1, xy_data *point2)
{
	dest->x = abs(point2->x - point1->x);
    dest->y = abs(point2->y - point1->y);
    step->x = (point1->x < point2->x) ? 1 : -1;
    step->y = (point1->y < point2->y) ? 1 : -1;
}

void draw_line(xy_data point1, xy_data point2, int z_value, t_vars *vars)
{
	xy_data dest;
	xy_data step;
	int err;
	int e2;

	init_steps(&dest, &step, &point1, &point2);
    err = dest.x - dest.y;
	e2;
    while (1)
	{
        my_mlx_pixel_put(vars, point1.x, point1.y, get_color(z_value));
        if (point1.x == point2.x && point1.y == point2.y)
			break;
        e2 = err * 2;
        if (e2 > -dest.y)
		{
            err -= dest.y;
            point1.x += step.x;
        }
        if (e2 < dest.x)
		{
            err += dest.x;
            point1.y += step.y;
        }
    }
	return ;
}

void calculate_dest(t_vars *vars, xy_data *dest, int i, int j, float a)
{
	dest->x = (j - i) * cos(a) * vars->block_size;
    dest->y = ((i + j) * sin(a) - (vars->matrix[i][j]) / HEIGHT_OFFSET ) * vars->block_size;
    dest->x = vars->offset.x + dest->x;
    dest->y = vars->offset.y + dest->y;
}

void calculate_above(t_vars *vars, xy_data *above, int i, int j, float a)
{
	above->x = (j - i + 1) * cos(a) * vars->block_size;
    above->y = ((i + j - 1) * sin(a) - (vars->matrix[i - 1][j]) / HEIGHT_OFFSET) * vars->block_size;
	above->x = vars->offset.x + above->x;
	above->y = vars->offset.y + above->y;
}

void reset_rows(int *j, xy_data *prev)
{
	*j = 0;
	prev->x = 0;
	prev->y = 0;
	return;
}

void draw_points(t_vars *vars)
{
	int i;
	int j;
	xy_data dest;
	xy_data prev;
	xy_data above;

	i = 0;
	while(i < vars->col)
	{
		reset_rows(&j, &prev);
		while(j < vars->row)
        {
			calculate_dest(vars, &dest, i, j, vars->a);
			if(i > 0)
			{
				calculate_above(vars, &above, i, j, vars->a);
				draw_line(above, dest, vars->matrix[i][j], vars);
			}
			if(prev.x && prev.y)
				draw_line(prev, dest, vars->matrix[i][j], vars);
			prev.x = dest.x;
			prev.y = dest.y;
			// i dont really need this as the line also dras the points
            // my_mlx_pixel_put(vars, dest.x, dest.y, get_color(vars->matrix[i][j]));
            j++;
        }
		i++;
	}
	return ;
}
