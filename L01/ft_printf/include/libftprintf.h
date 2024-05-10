/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:51:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/10 23:04:01 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);

int printchar(char c);
int printstr(char * str);
int	print_unsigned_dec(int n);
int print_address(unsigned int nbr);
int print_lower_hex(unsigned int nbr);
int print_upper_hex(unsigned int nbr);

#endif