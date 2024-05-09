/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:23:49 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/09 15:04:08 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

static void	recursive_print(long long num, unsigned int *res, char *base, int base_l)
{
	char	print;

	if (num >= base_l)
	{
		recursive_print (num / base_l, res, base , base_l);
		print = base[num % base_l];
		write(1, &print, 1);
		*res += 1;
	}
	else if (num < base_l)
	{	
		if(num >= 0 && num <= 9)
		{
			print = base[num % base_l];
			printf("print: %c", print);
			write(1, &print, 1);
			*res += 1;
		}
		else
		{
			print = base[num % base_l];
			write(1, &print, 1);
			*res += 1;
		}
	}
}

int		ft_putnbr_base(long long num, char *base)
{
	long long  base_l;
	base_l = strlen(base);
	unsigned int res;

	res = 0;
	if (num < 0)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = num * -1;
			res += 1;
			recursive_print(num, &res, base, base_l);
		}
		else if (num == -2147483648)
		{
			write(1, "-2147483648", 11);
			res = 11;
		}
	}
	else
	{
		recursive_print(num, &res, base, base_l);
	}
	return (res);
	
	
}

// int main(void)
// {
// 	printf("\nreturn value is %d\n", ft_putnbr_base(12345678, "0123456789abcdef"));
// 	return(0);
// }