/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:51:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/11 18:27:16 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);

int print_char(char c);
int print_str(char * str);
int	print_unsigned_dec(unsigned int n);
int print_address(unsigned long ptr);
int print_lower_hex(unsigned int nbr);
int print_upper_hex(unsigned int nbr);

#endif