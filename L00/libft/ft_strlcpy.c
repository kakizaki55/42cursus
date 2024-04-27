/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:41:46 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:29:44 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string.h>

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_length;

	src_length = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_length);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_length);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
// 	char str_dst[22];
// 	printf("return is %zu\n", ft_strlcpy(str_dst, str, 21));
// 	printf("%s",str_dst);
// }