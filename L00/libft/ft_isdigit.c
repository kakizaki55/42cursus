/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:23:22 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/02 14:29:16 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {	
// 	char one = '1';
// 	char Z = 'Z';
// 	char zero = '0';

// 	printf("c is %d\n", ft_isdigit(one));
// 	printf("Z is %d\n", ft_isdigit(Z));
// 	printf("zero is %d\n", ft_isdigit(zero));
// 	printf("original one is %d\n", isdigit(one));
// 	printf("original Z is %d\n", isdigit(Z));
// 	printf("original zero is %d\n", isdigit(zero));
// }
