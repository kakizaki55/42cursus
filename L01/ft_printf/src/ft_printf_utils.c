/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:51:29 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/11 17:20:39 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int print_char(char c)
{
	if(write(1, &c, 1) != -1)
	{
		return (1);
	}
	return (0);
}


int print_str(char * str)
{
	int i;
	if(!str)
	{
		ft_putstr("(null)");
		return (6);
	}
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

int	print_unsigned_dec(unsigned int n)
{
	return (ft_putnbr_long(n));
}

int print_lower_hex(unsigned int nbr)
{	
	return(ft_putnbr_base(nbr, "0123456789abcdef"));
}

int print_upper_hex(unsigned int nbr)
{
	return(ft_putnbr_base(nbr, "0123456789ABCDEF"));
}