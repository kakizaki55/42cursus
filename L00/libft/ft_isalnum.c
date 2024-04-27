/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:08:03 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 14:26:29 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {	
// 	char c = 'A';
// 	char k = 'z';
// 	char zero = '0';

// 	printf("c is %d\n", ft_isalnum(c));
// 	printf("k is %d\n", ft_isalnum(k));
// 	printf("zero is %d\n", ft_isalnum(zero));
// 	printf("original c is %d\n", isalnum(c));
// 	printf("original k is %d\n", isalnum(k));
// 	printf("original zero is %d\n", isalnum(zero));
// }