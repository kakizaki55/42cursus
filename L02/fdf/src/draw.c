/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:22:17 by minoka            #+#    #+#             */
/*   Updated: 2024/09/23 17:28:21 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	init_steps(xy_data *dest, xy_data *step, xy_data *point1,
		xy_data *point2)
{
	dest->x = abs(point2->x - point1->x);
	dest->y = abs(point2->y - point1->y);
	step->x = (point1->x < point2->x) ? 1 : -1;
	step->y = (point1->y < point2->y) ? 1 : -1;
}

void	draw_line(xy_data point1, xy_data point2, int z_value, t_vars *vars)
{
	xy_data	dest;
	xy_data	step;
	int		err;
	int		e2;

	init_steps(&dest, &step, &point1, &point2);
	err = dest.x - dest.y;
	while (1)
	{
		my_mlx_pixel_put(vars, point1.x, point1.y, get_color(z_value));
		if (point1.x == point2.x && point1.y == point2.y)
			break ;
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

void	draw_points(t_vars *vars)
{
	int		i;
	int		j;
	xy_data	dest;
	xy_data	prev;
	xy_data	above;

	i = 0;
	while (i < vars->col)
	{
		reset_rows(&j, &prev);
		while (j < vars->row)
		{
			calculate_dest(vars, &dest, i, j);
			if (i > 0)
			{
				calculate_above(vars, &above, i, j);
				draw_line(above, dest, vars->matrix[i][j], vars);
			}
			if (prev.x && prev.y)
				draw_line(prev, dest, vars->matrix[i][j], vars);
			prev.x = dest.x;
			prev.y = dest.y;
			j++;
		}
		i++;
	}
	return ;
}
