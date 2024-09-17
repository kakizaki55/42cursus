/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:16:09 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/17 17:44:50 by mkakizak         ###   ########.fr       */
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
		// temp = ft_atoi(array[i]);
		// if(temp > 10 || temp < -10)
		// {
		// 	#undef HEIGHT_OFFSET;
		// 	#define HEIGHT_OFFSET = 10;
		// }
		res[i] = ft_atoi(array[i]);
		i++;
	}
	res[i] = NULL;
	return (free_all(array), res);
}


int get_file_length(char *file_path)
{
	int res;
	int fd;

	// TODO: will add donditinal for different kinds of paths here

	file_path = ft_strjoin("test_maps/", file_path);
	fd = open(file_path, O_RDONLY);

	res = 0;
	while(1)
	{
	puts("check start 2:\n");
		char *str = get_next_line(fd);
		// ft_printf("%s\n", str);
		if(str == NULL)
			break;
		res++;
	puts("check end 2:\n");
	}
	// puts("does it leave the loop?");
	close(fd);
	// ft_printf("file_len 1: %d\n", res);
	return (res);
}


void parse_map(char *file_path, m_data *data)
{
	char	*str;
	int 	fd;

    int     **res;
	char	**array;
	int 	i;

	// this 11 needs to be lenght of the file. right now its set to 42.fdf
	//this isnt workig becouse get nextline will keep how many are being used so when it goes to the second loop it breaks

	int file_length;
	// int arr_length;

	// file_length = get_file_length(file_path);

	data->col = get_file_length(file_path);
	ft_printf("file_len 2:%d\n", data->col);


	res = ft_calloc(sizeof(int*), data->col + 1);
	if(res == NULL)
		return ;

	file_path = ft_strjoin("test_maps/", file_path);

	fd = open(file_path, O_RDONLY);
	if(fd == NULL)
		return ;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str)
		{
			puts("check start 3");
			array = ft_split(str, ' ');
			if(array == NULL)
				return ;
			ft_printf("length:%d\n" , str_arr_length(array));
			// arr_length = str_arr_length(array);
			// print_arr(array, str_arr_length(array));
			data->row = str_arr_length(array);


			res[i] = convert_to_int(array, data->row);
			ft_printf("check end:\n");
		}
		else
		{
			res[i] = NULL;
			break;
		}
		i++;
	}
	data->matrix = res;
	print_matrix(data->matrix, data->col, data->row);
	
	puts("does it get here?\n");
	close(fd);
    return ;
}
