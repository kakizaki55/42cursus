/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:51:29 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/11 22:48:11 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_print_char(char c)
{
	return(ft_putchar(c));
}

int	ft_print_unsigned_dec(unsigned int n)
{
	return (ft_putnbr_long(n));
}

int ft_print_lower_hex(unsigned int nbr)
{	
	return(ft_putnbr_base(nbr, "0123456789abcdef"));
}

int ft_print_upper_hex(unsigned int nbr)
{
	return(ft_putnbr_base(nbr, "0123456789ABCDEF"));
}