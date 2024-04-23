/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:20:25 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/23 12:50:25 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t src_length;
	size_t dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	i = 0;

	// if(dstsize < dst_length)
	// 	return (src_length);

	// if (dstsize == dst_length + 1) {
    //     dst[dst_length] = '\0';
    //     return (dst_length + src_length);
    // }
	
	if(dstsize == 0 )
		return (src_length + dst_length);
	
	if(dstsize <= dst_length)
		return (src_length + dstsize);
	
	if (dstsize == dst_length + 1) {
        dst[dst_length] = '\0';
		// puts("here i am ");
        return (src_length);
    }
	
	while(i < dstsize - dst_length - 1)
	{
		dst[i + dst_length] = src[i];	
		i++;
	}
	
	dst[i + dst_length] = '\0';
	return (src_length + dstsize);
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
	
// 	printf("mac: %d\n",4);
// 	// strlcat(s1, str, max);
// 	printf("%lu\n", strlcat(s1, "thx to ntoniolo for this test !", 4));
// 	printf("strlcat: %s\n",buff1);
	
// 	// ft_strlcat(s2, str, max);
// 	printf("%lu \n", ft_strlcat(s2, "thx to ntoniolo for this test !", 4));
// 	printf("ft_strlcat: %s\n", buff2);
	
// }