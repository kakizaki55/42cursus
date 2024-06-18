/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:29:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/18 13:28:00 by mkakizak         ###   ########.fr       */
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

// int is_bigger(int a, int b)
// {
// 	if(a > b)
// 		return (true);
// 	return (false);
// }

int find_min_index(int *arr, int len)
{
	int i;
	int temp;
	int res;

	temp = INT_MAX;
	i = 0 ;

	while(i < len)
	{
		if(is_smaller(arr[i], temp))
		{
			temp = arr[i];
			res = i;
		}
		i++;
	}
	return (res);
}

// int find_max_index(int *arr, int len)
// {
// 	int i;
// 	int temp;
// 	int res;

// 	temp = INT_MIN;

// 	i = 0 ;

// 	while(i < len)
// 	{
// 		if(is_bigger(arr[i], temp))
// 		{
// 			temp = arr[i];
// 			res = i;
// 		}
// 		i++;
// 	}
// 	return (res);
// }


int *compress(int *arr, int len)
{	
	int *res;
	res = ft_calloc(sizeof(int), len);
	if(res == NULL)
		return (NULL);
	int min_i;

	int i;
	int j;
	i = 0;
	j = 1;

    while (i < len) {
        min_i = find_min_index(arr, len);
        res[min_i] = j++;

        arr[min_i] = INT_MAX;
        i += 1;
    }

	return (free(arr), res);
}
