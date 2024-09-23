/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:09:06 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/23 17:22:46 by mkakizak         ###   ########.fr       */
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

int	get_color(int z_value)
{
	int	seg;
	int	offset;
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	z_value = abs(z_value) * 10 % 1530;
	seg = z_value / 255;
	offset = z_value % 255;
	if (seg < 2)
	{
		r = 200;
		g = seg == 0 ? offset : 255 - offset;
	}
	else if (seg < 4)
	{
		b = seg == 3 ? 200 : offset;
		r = seg == 2 ? 200 : 255 - offset;
	}
	else
	{
		b = seg == 4 ? 200 : 255 - offset;
		g = seg == 4 ? offset : 200;
	}
	return (color_hex(100, r, g, b));
}
