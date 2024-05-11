/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:23:49 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/11 22:12:21 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursive_print(unsigned long num, unsigned int *res, char *base, unsigned long base_l)
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
			if(write(1, &print, 1) != -1)
				*res += 1;
			else 
				return (-1);
		}
		else
		{
			print = base[num % base_l];
			if(write(1, &print, 1) != -1)
				*res += 1;
			else 
				return (-1);
		}
	}
	return (0);
}

int		ft_putnbr_base(unsigned long num, char *base)
{
	unsigned long  base_l;
	base_l = (unsigned long)ft_strlen(base);
	unsigned int res;

	res = 0;
	if(recursive_print(num, &res, base, base_l) == -1)
		return (-1);
	return (res);
}
