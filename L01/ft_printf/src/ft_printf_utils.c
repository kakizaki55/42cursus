/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:51:29 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/09 15:13:43 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int printchar(char c)
{
	if(write(1, &c, 1) != -1)
	{
		return (1);
	}
	return (0);
}

int printstr(char * str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if(write(1, &str[i], 1) != -1)
		{
			i++;
		} 
		else
		{
			return (0);
		}
	}
	return(i);
}

static void	recursive_print( int num, unsigned int *res)
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

int	print_unsigned_nbr(int n)
{
	unsigned int res;
	res = 0;
		recursive_print(n, &res);
	return (res);
}

int print_lower_hex(unsigned int nbr)
{	
	return(ft_putnbr_base(nbr, "0123456789abcdef"));
}

int print_upper_hex(unsigned int nbr)
{
	return(ft_putnbr_base(nbr, "0123456789ABCDEF"));
}


int print_address(unsigned int nbr)
{
	int i;
	if(write(1, "0x", 2) != -1)
	{
			i++;
	}
	
	i += ft_putnbr_base(nbr, "0123456789abcdef");
	return(i);
}

