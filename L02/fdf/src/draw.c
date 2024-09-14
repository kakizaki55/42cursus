/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:22:17 by minoka            #+#    #+#             */
/*   Updated: 2024/09/14 18:57:49 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	// if(data->img == NULL);
	// 	return ;
	// printf("x:%d\n", x);
	// printf("y:%d\n", y);
	// printf("color:%x\n", color);
	// print_img(*data);

	dst = NULL;
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
		*(unsigned int *)dst = color;

	}

}

void draw_line(xy_data point1, xy_data point2, int z_value, t_vars *vars)
{

	if(point1.x == NULL || point2.x == NULL)
		return ;
    int x0 = point1.x, y0 = point1.y;
    int x1 = point2.x, y1 = point2.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

	puts("does it get here");
    while (1) {
		
        my_mlx_pixel_put(vars, x0, y0, get_color(z_value));
        if (x0 == x1 && y0 == y1) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
	return ;
}


void draw_points(m_data *data, t_vars *vars)
{
	xy_data offset;
	xy_data dest;
	int i;
	int j;
	float a;
	xy_data vert = { NULL, NULL };
	xy_data hor = { NULL, NULL };

	offset.x = WINDOW_WIDTH / 2;
	offset.y = WINDOW_HEIGHT / 3;

	a = atan(1 / sqrt(2));
	// a = 1.0;

	// printf("a:%f\n", a);
	i = 0;
	print_matrix(data->matrix, data->col, data->row);
	ft_printf("row:%d\n", data->row);
	ft_printf("col:%d\n", data->col);

	while(i < data->col)
	{
		j = 0;
		vert.x = NULL;
		vert.y = NULL;
		// col = str_arr_length(matrix[i]);
		// ft_printf("col:%d\n",col);

		while(j < data->row)
        {
			//what the hell is this?
            dest.x = (j - i) * cos(a) * BLOCK_SIZE;
            dest.y = ((i + j) * sin(a) - (data->matrix[i][j]) / HEIGHT_OFFSET ) * BLOCK_SIZE;

            dest.x = offset.x + dest.x;
            dest.y = offset.y + dest.y;
			// ft_printf("dest x: %d\n", (int)dest.x);
			// ft_printf("dest y: %d\n", (int)dest.y);
			if(i > 0)
			{
				//and this?
				hor.x = (j - i + 1) * cos(a) * BLOCK_SIZE;
            	hor.y = ((i + j - 1) * sin(a) - (data->matrix[i -1][j]) / HEIGHT_OFFSET) * BLOCK_SIZE;
				hor.x = offset.x + hor.x;
				hor.y = offset.y + hor.y;
				ft_printf("z_value :%d\n", data->matrix[i][j]);
				draw_line(hor, dest, 0, vars);
			}

			if(vert.x && vert.y)
				draw_line(vert, dest, 0, vars);

			vert.x = dest.x;
			vert.y = dest.y;

            my_mlx_pixel_put(vars, dest.x, dest.y, get_color(data->matrix[i][j]));
            j++;
        }
		i++;
	}
	return ;
}
