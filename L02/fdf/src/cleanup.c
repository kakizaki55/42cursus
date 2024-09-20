/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:09:18 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/20 17:16:47 by minoka           ###   ########.fr       */
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

void free_vars(t_vars *vars)
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

// void free_matrix(int **matrix, int row, int col)
// {
//     int i;
//     int j;

//     // if (!matrix || row == 0 || col == 0)
//     //     return;

//     i = 0;
//     j = 0;
//     while(i < col)
//     {
//         free(matrix[i]);
//         i++;
//     }
// }

// void free_m_data( *data) {
//     if (data == NULL) {
//         return;
//     }

//     if (data->matrix != NULL) {
//         for (int i = 0; i < data->row; i++) {
//             if (data->matrix[i] != NULL) {
//                 free(data->matrix[i]);
//                 data->matrix[i] = NULL;
//             }
//         }
//         free(data->matrix);
//         data->matrix = NULL;
//     }

//     // Note: We're not freeing 'data' itself here
//     data->row = 0;
//     data->col = 0;
// }

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