/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:20:25 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:29:14 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_length;
	size_t	dst_length;
	size_t	res;
	size_t	cut_length;

	res = 0;
	if ((dst == NULL || src == NULL) && dstsize == 0)
		return (dstsize);
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	cut_length = 0;
	i = 0;
	if (dstsize > dst_length)
	{
		cut_length = dstsize - dst_length - 1;
		res = src_length + dst_length;
	}
	else
	{
		res = src_length + dstsize;
	}
	while (i < cut_length && src[i] != '\0')
	{
		dst[i + dst_length] = src[i];
		i++;
	}
	if (cut_length)
		dst[i + dst_length] = '\0';
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	// char *str = "the cake is a lie !\0I'm hidden lol\r\n";
// 	char buff1[0xF00] = "there is no stars in the sky";
// 	char buff2[0xF00] = "there is no stars in the sky";
// 	// size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

// 	char s1[4] = "";
// 	char s2[4] = "";
	
// 	// printf("mac: %d\n",4);
// 	// strlcat(s1, str, max);
// 	printf("%lu\n", strlcat((void *)0, "" -1, 0));
// 	printf("strlcat: %s\n","");
	
// 	// ft_strlcat(s2, str, max);
// 	printf("%lu \n", ft_strlcat((void *)0, "" - 1, 0));
// 	printf("ft_strlcat: %s\n", "");
	
// }