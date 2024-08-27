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
	res = ft_calloc(sizeof(int*), len);
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
	// this 11 needs to be lenght of the file. right now its set to 42.fdf
	res = ft_calloc(sizeof(int*), 11);

    bool = TRUE;
	for (int i = 0; bool; i++)
	{
		str = get_next_line(fd);
		if (str)
		{
			// ft_printf("%s\n", str);
			array = ft_split(str, ' ');
			if(array == NULL)
				return (NULL);
			// // same with this 19 need to be the lenght of the array.i t is now set for 42.fdf
			res[i] = convert_to_int(array, 19);
			// print_arr(res[i], 19);
			// puts("\n");
		}
		else
			// free_all(array);
			bool = FALSE;
	}
	print_matrix(res, 11, 19);
    return (res);
}
