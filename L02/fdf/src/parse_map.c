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

int **parse_map(int fd)
{
	char	*file_path;
	int		bool;
	char	*str;

    int     **res;
	char	**array;
	int 	i;
	// this 11 needs to be lenght of the file. right now its set to 42.fdf
	//this isnt workig becouse get nextline will keep how many are being used so when it goes to the second loop it breaks

	// int file_length = 0;
	// while(1)
	// {
	// 	char *str = get_next_line(fd);
	// 	ft_printf("%s\n", str);
	// 	if(str == NULL)
	// 		break;
	// 	file_length ++;
	// }
	// ft_printf("file_len: %d\n", file_length);
	// res = ft_calloc(sizeof(int*), file_length + 1);

	res = ft_calloc(sizeof(int*), 11 + 1);

    bool = TRUE;
	i = 0;
	while (bool)
	{
		str = get_next_line(fd);
		if (str)
		{
			array = ft_split(str, ' ');
			if(array == NULL)
				return (NULL);
			// // same with this 19 need to be the lenght of the array.i t is now set for 42.fdf

			res[i] = convert_to_int(array, str_arr_length(array));
		}
		else
		{
			res[i] = NULL;
			bool = FALSE;
		}
		i++;
	}
	// print_matrix(res, 11, 19);
    return (res);
}
