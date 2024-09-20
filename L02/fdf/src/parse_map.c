/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:16:09 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/20 17:19:00 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>


int *convert_to_int(char **array, int len)
{
	int i;
	int *res;
	int temp;

	i = 0;
	res = ft_calloc(sizeof(int), len + 1);
	if( res == NULL)
		return (NULL);
	while(array[i])
	{
		res[i] = ft_atoi(array[i]);
		i++;
	}
	// res[i] = (int)NULL;
	return (free_all(array), res);
}


int get_file_length(char *file_path)
{
	int 	res;
	int 	fd;
	char 	*str;

	// TODO: will add donditinal for different kinds of paths here

	file_path = ft_strjoin("test_maps/", file_path);
	if(file_path == NULL)
		return (0);
	fd = open(file_path, O_RDONLY);
	if(fd == -1)
		return (free(file_path), 0);
	free(file_path);
	res = 0;
	while(1)
	{
		str = get_next_line(fd);
		// ft_printf("%s\n", str);
		if(str == NULL)
			break;
		free(str);
		res ++;
	}
	// puts("does it leave the loop?");
	close(fd);
	// ft_printf("file_len 1: %d\n", res);
	return (res);
}


void parse_map(char *file_path, t_vars *vars)
{
	char	*str;
	int 	fd;

    int     **res;
	char	**array;
	int 	i;


	int file_length;
	// int arr_length;

	// file_length = get_file_length(file_path);

	vars->col = get_file_length(file_path);
	// ft_printf("file_len 2:%d\n", vars->col);


	res = (int **)ft_calloc(sizeof(int*), vars->col + 1);
	if(res == NULL)
		return ;

	// file_path = ft_strjoin("test_maps/", file_path);

	// fd = open(file_path, O_RDONLY);
	// if(fd == NULL)
	// 	return ;

	file_path = ft_strjoin("test_maps/", file_path);
	if(file_path == NULL)
		return ;
	fd = open(file_path, O_RDONLY);
	if(fd == -1)
		return (free(file_path));
	free(file_path);

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str)
		{
			// puts("check start 3");
			array = ft_split(str, ' ');
			if(array == NULL)
				return ;
			// ft_printf("length:%d\n" , str_arr_length(array));
			// arr_length = str_arr_length(array);
			// print_arr(array, str_arr_length(array));
			vars->row = str_arr_length(array);


			res[i] = convert_to_int(array, vars->row);
			free(str);
		}
		else
		{
			// res[i] = (int)NULL;
			break;
		}
		i++;
	}
	vars->matrix = res;
	// print_matrix(data->matrix, data->col, data->row);
	close(fd);
    return;
}
