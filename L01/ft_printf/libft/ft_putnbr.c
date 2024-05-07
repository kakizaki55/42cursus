/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:30:35 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/07 17:42:43 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_print( int num, int *res)
{
	char	print;

	if (num >= 10)
	{
		recursive_print (num / 10, res);
		print = num % 10 + '0';
		write(1, &print, 1);
		*res += 1;
	}
	else if (num < 10)
	{
		print = num % 10 + '0';
		write(1, &print, 1);
		*res += 1;
	}
}

int	ft_putnbr(int n)
{
	int res;

	res = 0;
	if (n < 0)
	{
		if (n > INT_MIN)
		{
			write(1, "-", 1);
			n = n * -1;
			res += 1;
			recursive_print(n, &res);
		}
		else if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			res = 11;
		}
	}
	else
	{
		recursive_print(n, &res);
	}
	return (res);
}
