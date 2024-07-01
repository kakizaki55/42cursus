/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:27:04 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/01 13:44:50 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

int print_arr(int *arr, int len)
{
	int i;
	i = 0;

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
	long nbr;

	args_array = ft_calloc(sizeof(int), argc);
	if(args_array == NULL)
		return (NULL);

	i = 1;

	while(i < argc)
	{	
		// long max = 1844674407370955161;
		nbr = ft_atoi_long(argv[i]);
		// printf("%lu\n", LONG_MAX);
		// printf("%lu\n", INT_MAX);
		if(nbr < INT_MAX && nbr > INT_MIN) 
			args_array[i - 1] = nbr;
		else
		{
			ft_printf("Error\n");
			// free(args_array);
		}
		//  need some kinda of error check here but how do i do it with out using 0 and -1;
		// also need to remember to free everything is somthing goes wrong.
		i++;
	}
	// args_array[i + 1] = NULL;
	return (args_array);
}
