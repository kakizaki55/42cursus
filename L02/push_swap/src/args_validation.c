/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:27:04 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/14 13:22:20 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

int arr_len(int *arr)
{
	int res;

	res = 0;
	while(arr[res] != NULL)
	{
		res++;
	}
	return (res);
}

int print_arr(int *arr)
{
	int i;

	int len = arr_len(arr);
	while (i < len)
	{
		ft_printf("%d", arr[i]);
		i++;
	}
}

int *args_validation(int argc, char *argv[])
{	
	int i;
	int *args_array;

	args_array = ft_calloc(sizeof(int), argc);
	if(args_array == NULL)
		return (args_array);
	if(argc < 2)
		return (false);

	i = 1;

	while(i < argc)
	{	
		int nbr;
		nbr = ft_atoi(argv[i]);
		args_array[i - 1] = nbr;
		//need some kinda of error check here but how do i do it with out using 0 and -1;
		i++;
	}

	return (args_array);
}
