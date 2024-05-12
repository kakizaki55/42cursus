/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:51:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/12 20:11:05 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_str(char *str);
int	ft_print_unsigned_dec(unsigned int n);
int	ft_print_address(unsigned long ptr);
int	ft_print_lower_hex(unsigned int nbr);
int	ft_print_upper_hex(unsigned int nbr);

#endif