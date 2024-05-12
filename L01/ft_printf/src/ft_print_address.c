/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:45:25 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/12 18:54:05 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_address(unsigned long ptr)
{
	int	res;

	res = 0;
	if (write(1, "0x", 2) != -1)
		res = 2;
	else
		return (-1);
	return (ft_putnbr_base(ptr, "0123456789abcdef") + res);
}
