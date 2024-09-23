/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:09:18 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/23 17:23:10 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	distroy_vars(t_vars *vars)
{
	if (vars && vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars && vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars && vars->matrix)
		free_matrix(vars->matrix);
	free(vars->mlx);
	free(vars);
	return ;
}

void	distroy_and_exit(t_vars *vars, int error_code, char *message)
{
	distroy_vars(vars);
	if (message)
	{
		if (!ft_strncmp(message, "Not .fdf file\n", 14))
		{
			write(STDERR_FILENO, message, 14);
			exit(error_code);
		}
		if (!ft_strncmp(message, "Please put in a file name\n", 27))
		{
			write(STDERR_FILENO, message, 27);
			exit(error_code);
		}
		perror(message);
	}
	exit(error_code);
}

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
