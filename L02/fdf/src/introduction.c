/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:06:36 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/22 19:51:12 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fdf.h>

void	print_menu(t_vars *vars)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = vars->mlx;
	win = vars->win;
	mlx_string_put(mlx, win, 65, y += 20, 0xFFFFFF, "How to Use");
}