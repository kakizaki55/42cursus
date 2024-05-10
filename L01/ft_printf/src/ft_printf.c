/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:31:44 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/09 15:16:35 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

long long	check_token(char c, va_list arg_ptr)
{
	char chr;
	char *str;
	void *ptr;
	int nbr;
	int nbr_int;
	unsigned int unsigned_nbr;
	int hex_nbr;

	unsigned int res;

	if(c == 'c')
	{
		chr = va_arg(arg_ptr, int);
		return (printchar(chr));
	}
	else if(c == 's')
	{
		str = va_arg(arg_ptr, char *);
		return (printstr(str));
	}
	else if(c == 'p')
	{
		// not sure how to print the memoy address here yet. 
		ptr = va_arg(arg_ptr, void *);
		// printf("ptr is : %p", ptr);
		// return (print_address((unsigned int)ptr));
	}
	else if(c == 'd' || c == 'i')
	{
		nbr = va_arg(arg_ptr, int);
		return(ft_putnbr(nbr));
	}
	else if(c == 'u')
	{
		unsigned_nbr = va_arg(arg_ptr, unsigned int);
		return (print_unsigned_nbr(nbr));
	}
	else if(c == 'x')
	{
		nbr = va_arg(arg_ptr, int);
		return (print_lower_hex((unsigned int) nbr));
	}
	else if(c == 'X')
	{
		nbr = va_arg(arg_ptr, int);
		return (print_upper_hex((unsigned int) nbr));
	}
	else if(c == '%')
	{
		ft_putchar('%');
		return(1);
	}
	
	return (0);
}


int	ft_printf(const char *format, ...)
{

	va_list		arg_ptr;
	long long	res;

	res = 0;
	
	// need to make a parser to figer out each token and see which for mat it needs to print
	// use va_start and pass format as the beginnign of the va args. 

	va_start(arg_ptr, format);

	while(*format)
	{
		if(*format == '%' )
		{
			format++;
			if(!*format)
				return(res);
			res += check_token(*format, arg_ptr);
		}
		else
		{
			ft_putchar(*format);	
			res++;
		}
		format++;
	}
	va_end(arg_ptr);
	return(res);
}
