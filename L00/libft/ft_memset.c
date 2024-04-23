/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:37:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/17 12:28:25 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memset(void *b, int c, size_t len)
{	
	unsigned char	*p;
	size_t			count;

	p = b;
	count = 0;
	while (count < len)
	{
		*p = c;
		p++;
		count++;
	}
	return (b);
}

// #include <string.h>
// #include <stdio.h>
// #define  BUF_SIZE  20
// int main(void)
// {
//    char buffer[BUF_SIZE + 1];
//    char *string;
//    ft_memset(buffer, 0, sizeof(buffer));

//    string = (char *) memset(buffer,'A', 10);
//    printf("\nBuffer contents: %s\n", string);

//    ft_memset(buffer+10, 'B', 5);
//    printf("\nBuffer contents: %s\n", buffer);
// }