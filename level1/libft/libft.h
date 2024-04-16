/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:36:52 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/16 17:41:33 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
#include <string.h>

int	ft_isalpha(char c);
int	ft_isdigit(char c);
int	ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int	ft_strlen(char *str);
void *ft_memset(void *b, int c, size_t len);


#endif