/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:34:03 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/23 17:34:05 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_matrix(int **matrix, int col, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < col)
	{
		ft_printf("i[%d] ", i);
		while (j < row)
		{
			ft_printf("%d\n[%d]", j, matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	str_arr_length(char **array)
{
	int	i;

	if (array == NULL || *array == NULL)
		return (0);
	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

int	int_arr_length(int *array)
{
	int	i;

	if (array == NULL)
		return (0);
	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}
