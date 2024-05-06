/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:52:24 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/02 14:28:39 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	if (c >= 'A' && c <= 'Z')
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
// 	printf("c is %d\n", ft_isalpha(c));
// 	printf("k is %d\n", ft_isalpha(k));
// 	printf("zero is %d\n", ft_isalpha(zero));
// 	printf("original c is %d\n", isalpha(c));
// 	printf("original k is %d\n", isalpha(k));
// 	printf("original zero is %d\n", isalpha(zero));
// }
