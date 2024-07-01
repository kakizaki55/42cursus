/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:27:04 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:46 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void error()
{
	// ft_printf("Error::::\n");
	write(2, "Error\n", 7);
	exit(1);
}


int *args_validation(int argc, char *argv[])
{	
	int i;
	int *args_array;
	long nbr;
	int j;

	args_array = ft_calloc(sizeof(int), argc);
	if(args_array == NULL)
		return (NULL);

	i = 1;
	// ft_printf("here argc:%d\n", argc);
	while(i < argc)
	{	j = 0;
		nbr = ft_atoi_long(argv[i]);
		if(!(nbr <= INT_MAX && nbr >= INT_MIN))
			error();
		while(j < i)
		{
			if(nbr == args_array[j])
			{
				free(args_array);
				error();
			}
			j++;
		}
		args_array[i - 1] = nbr;
		i++;
	}
	return (args_array);
}
