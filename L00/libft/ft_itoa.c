/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:45:57 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/24 20:44:57 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int get_length(int n)
{
	int count;

	count = 0;
	while(n != 0)
	{
		n /= 10;
		count++;
	}
	return(count);
}

int power(int x, int y)
{
	int i;
	int base;

	i = 0;
	base = x;
	while (i < y)
	{
		base *= x;
	}
	return (base);
}

char *ft_itoa(int n)
{
	int i;
	char * res;
	int power;
	// need to find power of the int and use malloc to allocated enough space for the string repersentation
	power = get_length(n) - 1;
	// puts("%d",);
	// 10 

	return("123");
}


int main(void)
{
	int int_max = __INT_MAX__;

	// printf("int max is :%s \n", ft_itoa(int_max));
	printf("int max is :%s \n", ft_itoa(int_max));
	// printf("int max is :%s \n", itoa(int_max));
}