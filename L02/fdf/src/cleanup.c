/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:09:18 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/14 20:32:25 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef struct s_vars
// {
// 	void 	*mlx;
// 	void 	*win;
// 	void 	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_vars;

#include<fdf.h>

void clean_up_vars(t_vars *vars)
{
    if(vars && vars->mlx)
        free(vars->mlx);
    if(vars && vars->win)
        free(vars->win);
    if(vars && vars->img)
        free(vars->img);
    if(vars && vars->addr)
        free(vars->addr);
    if(vars)
        free(vars);
    return ;
}