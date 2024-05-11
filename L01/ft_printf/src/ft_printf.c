/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:31:44 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/11 22:48:49 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

unsigned int	check_token(char c, va_list arg_ptr)
{
	char chr;
	char *str;
	void *ptr;
	int nbr;
	unsigned int unsigned_nbr;

	if(c == 'c')
	{
		chr = va_arg(arg_ptr, int);
		return (ft_print_char(chr));
	}
	else if(c == 's')
	{
		str = va_arg(arg_ptr, char *);
		return (ft_print_str(str));
	}
	else if(c == 'p')
	{
		ptr = va_arg(arg_ptr, void *);
		return (ft_print_address((unsigned long)ptr));
	}
	else if(c == 'd' || c == 'i')
	{
		nbr = va_arg(arg_ptr, int);
		return (ft_putnbr(nbr));
	}
	else if(c == 'u')
	{
		unsigned_nbr = va_arg(arg_ptr, int);
		return (ft_print_unsigned_dec(unsigned_nbr));
	}
	else if(c == 'x')
	{
		nbr = va_arg(arg_ptr, int);
		return (ft_print_lower_hex((unsigned int) nbr));
	}
	else if(c == 'X')
	{
		nbr = va_arg(arg_ptr, int);
		return (ft_print_upper_hex((unsigned int) nbr));
	}
	else if(c == '%')
	{
		if(ft_putchar('%') != -1)
			return(1);
		else 
			return (-1);
	}
	
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			arg_ptr;
	int	res;
	int prev_res;
	if(format == NULL)
		return(-1);

	res = 0;
	va_start(arg_ptr, format);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			if(!*format)
				return(res);
			prev_res = res;
			res += check_token(*format, arg_ptr);
			if(res < prev_res)
				return (-1);
		}
		else
		{
			if(ft_putchar(*format) != -1)
				res++;
			else 
				return (-1);
		}
		format++;
	}
	va_end(arg_ptr);
	return(res);
}
