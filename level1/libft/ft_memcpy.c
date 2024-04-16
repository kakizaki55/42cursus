/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:12:01 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/16 19:32:26 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
void ft_memcpy(void * dst, const void *src, size_t n)
{	
	const unsigned char	*srcstr;
	unsigned char	*dststr;
	dststr = dst;
	srcstr = src;
	
	while (n > 0)
	{
		*dststr = (unsigned char)srcstr;
		dststr++;
		srcstr++;
		n--;
	}
	return ;
}