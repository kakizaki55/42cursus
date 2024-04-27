/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:20:25 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 18:46:51 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	find(size_t dstsize, size_t dst_l, size_t src_l, size_t *cut_l)
{
	if (dstsize > dst_l)
	{
		*cut_l = dstsize - dst_l - 1;
		return (src_l + dst_l);
	}
	else
	{
		return (src_l + dstsize);
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_l;
	size_t	dst_l;
	size_t	res;
	size_t	cut_l;

	res = 0;
	if ((dst == NULL || src == NULL) && dstsize == 0)
		return (dstsize);
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	cut_l = 0;
	i = 0;
	res = find(dstsize, dst_l, src_l, &cut_l);
	while (i < cut_l && src[i] != '\0')
	{
		dst[i + dst_l] = src[i];
		i++;
	}
	if (cut_l)
		dst[i + dst_l] = '\0';
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