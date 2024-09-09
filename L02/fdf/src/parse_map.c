/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:16:09 by mkakizak          #+#    #+#             */
/*   Updated: 2024/08/21 17:35:07 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>


int *convert_to_int(char **array, int len)
{
	int i;
	int *res;

	i = 0;
	res = ft_calloc(sizeof(int), len);
	if( res == NULL)
		return (NULL);
	while(array[i])
	{
		res[i] = ft_atoi(array[i]);
		i++;
	}
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
		char *str = get_next_line(fd);
		// ft_printf("%s\n", str);
		if(str == NULL)
			break;
		res ++;
	}
	close(fd);
	// ft_printf("file_len: %d\n", res);
	return (res);
}


void parse_map(char *file_path, m_data *data)
{
	int		bool;
	char	*str;
	int 	fd;

    int     **res;
	char	**array;
	int 	i;

	// this 11 needs to be lenght of the file. right now its set to 42.fdf
	//this isnt workig becouse get nextline will keep how many are being used so when it goes to the second loop it breaks

	int file_length;
	int arr_length;

	file_length = get_file_length(file_path);
	data->col = file_length;
	res = ft_calloc(sizeof(int*), file_length + 1);

	file_path = ft_strjoin("test_maps/", file_path);
	fd = open(file_path, O_RDONLY);

    bool = TRUE;
	i = 0;
	while (bool)
	{
		str = get_next_line(fd);
		if (str)
		{
			array = ft_split(str, ' ');
			if(array == NULL)
				return ;
			// ft_printf("length:%d\n" , str_arr_length(array));
			arr_length = str_arr_length(array);
			data->row =arr_length;
			res[i] = convert_to_int(array, arr_length);
		}
		else
		{
			res[i] = NULL;
			bool = FALSE;
		}
		i++;
	}
	print_matrix(res, file_length, arr_length);
	data->matrix = res;
	close(fd);
    return ;
}
