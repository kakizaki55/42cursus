/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:31:44 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/07 16:55:55 by mkakizak         ###   ########.fr       */
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
	int nbr_float;
	int nbr_int;
	unsigned int unsigned_int_nbr;
	int hex_nbr;

	if(c == 'c')
	{
		chr = va_arg(arg_ptr, int);
		printf("%c", chr); fflush(stdout);
		return (1);
	}
	else if(c == 's')
	{
		str = va_arg(arg_ptr, char *);
		printf("%s", str); fflush(stdout);
		return (ft_strlen(str));
	}
	else if(c == 'p')
	{
		ptr = va_arg(arg_ptr, void *);
		printf("%p", ptr); fflush(stdout);
		return (ft_strlen(str));
	}
	else if(c == 'd')
	{
		nbr_float = va_arg(arg_ptr, int);
		printf("%d", nbr_float); fflush(stdout);
		return (ft_strlen(str));
	}
	else if(c == 'i')
	{
		nbr_int = va_arg(arg_ptr, int);
		printf("%i", nbr_int); fflush(stdout);
		return (ft_strlen(str));
	}
	else if(c == 'u')
	{
		unsigned_int_nbr = va_arg(arg_ptr, unsigned int);
		printf("%u", unsigned_int_nbr); fflush(stdout);
		return (ft_strlen(str));
	}
	else if(c == 'x' || c == 'X')
	{
		hex_nbr = va_arg(arg_ptr, int);
		printf("%x", hex_nbr); fflush(stdout);
		return (ft_strlen(str));
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
	return(res);
}