/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:29:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/17 13:55:44 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

int is_smaller(int a, int b)
{
	if(a < b)
		return (true);
	return (false);
}

int is_bigger(int a, int b)
{
	if(a > b)
		return (true);
	return (false);
}

int *compress(int *arr)
{	
	int res[arr_len(arr)];
	res[0] = NULL;

	// need to compress this files so i can replace all ints with number starting from 1 and all the way up. 
	int small;
	int big;
	int i;

	small = 1;
	big = arr_len(arr);
	i = 0 ;

	while(arr[i] != NULL)
	{
		ft_printf("i is: %d\n", i);
		i++;
	}

	return (res);
}