/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:22:17 by minoka            #+#    #+#             */
/*   Updated: 2024/09/10 14:05:53 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void draw_line(xy_data point1, xy_data point2, int z_value, t_data *img)
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

    while (1) {
        my_mlx_pixel_put(img, x0, y0, get_color(z_value));
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


void draw_points(int **matrix, t_data *img, int row_len, int col_len)
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
	// printf("a:%f\n", a);
	i = 0;
	// print_matrix(matrix, 11, 19)

	while(i < col_len)
	{
		j = 0;
		vert.x = NULL;
		vert.y = NULL;
		// col = str_arr_length(matrix[i]);
		// ft_printf("col:%d\n",col);

		while(j < row_len)
        {
			//what the hell is this?
            dest.x = (j - i) * cos(a) * BLOCK_SIZE;
            dest.y = ((i + j) * sin(a) - (matrix[i][j]) / HEIGHT_OFFSET ) * BLOCK_SIZE;

            dest.x = offset.x + dest.x;
            dest.y = offset.y + dest.y;
			// ft_printf("dest x: %d\n", (int)dest.x);
			// ft_printf("dest y: %d\n", (int)dest.y);
			if(i > 0)
			{
				//and this?
				hor.x = (j - i + 1) * cos(a) * BLOCK_SIZE;
            	hor.y = ((i + j - 1) * sin(a) - (matrix[i -1][j]) / HEIGHT_OFFSET) * BLOCK_SIZE;
				hor.x = offset.x + hor.x;
				hor.y = offset.y + hor.y;
				ft_printf("z_value :%d\n", matrix[i][j]); fflush(stdout);
				draw_line(hor, dest, 0, img);
			}

			if(vert.x && vert.y)
				draw_line(vert, dest, 0, img);

			vert.x = dest.x;
			vert.y = dest.y;

            if (dest.x >= 0 && dest.x < WINDOW_WIDTH && dest.y >= 0 && dest.y < WINDOW_HEIGHT)
            {
                my_mlx_pixel_put(img, dest.x, dest.y, get_color(matrix[i][j]));
            }
            j++;
        }
		i++;
	}
	return ;
}
