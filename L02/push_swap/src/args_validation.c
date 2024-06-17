/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:27:04 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/17 13:22:07 by mkakizak         ###   ########.fr       */
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
	int len;
	i = 0;

	len = arr_len(arr);
	while (i < len)
	{
		ft_printf("[%d]:%d\n", i, arr[i]);
		i++;
	}
	return (0);
}

int *args_validation(int argc, char *argv[])
{	
	int i;
	int *args_array;
	//leavering one more args so i can fill it with a NULL Value
	args_array = ft_calloc(sizeof(int), argc);
	if(args_array == (void *)NULL)
		return (NULL);
	if(argc < 2)
		return (NULL);

	i = 1;

	while(i < argc)
	{	
		int nbr;
		nbr = ft_atoi(argv[i]);
		// ft_printf("nbr:%d\n", nbr);
		args_array[i - 1] = nbr;
		//need some kinda of error check here but how do i do it with out using 0 and -1;
		// also need to remember to free everything is somthing goes wrong.
		i++;
	}
	args_array[i + 1] = NULL;

	print_arr(args_array);

	return (args_array);
}
