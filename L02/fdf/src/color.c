/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:09:06 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/23 18:41:41 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	color_hex(int t, unsigned int r, unsigned int g, unsigned int b)
{
	int	color;

	color = 0x000000;
	if (r > 256 || g > 256 || b > 256)
		return (0x000000);
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_seg_1(t_c_data *color, int seg, int offset)
{
	color->r = 200;
	if (seg == 0)
		color->g = offset;
	else
		color->g = 255 - offset;
}

void	set_seg_2(t_c_data *color, int seg, int offset)
{
	if (seg == 3)
		color->b = 200;
	else
		color->b = offset;
	if (seg == 2)
		color->r = 200;
	else
		color->r = 255 - offset;
}

void	set_seg_3(t_c_data *color, int seg, int offset)
{
	if (seg == 4)
		color->b = 200;
	else
		color->b = 255 - offset;
	if (seg == 5)
		color->g = offset;
	else
		color->g = 255;
}

int	get_color(int z_value)
{
	int			seg;
	int			offset;
	t_c_data	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	z_value = abs(z_value) * 10 % 1530;
	seg = z_value / 255;
	offset = z_value % 255;
	if (seg < 2)
	{
		set_seg_1(&color, seg, offset);
	}
	else if (seg < 4)
	{
		set_seg_2(&color, seg, offset);
	}
	else
	{
		set_seg_3(&color, seg, offset);
	}
	return (color_hex(100, color.r, color.g, color.b));
}
