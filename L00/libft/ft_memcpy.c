/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:12:01 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:16:25 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstbuff;
	unsigned char	*srcbuff;
	size_t			i;

	dstbuff = (unsigned char *)dst;
	srcbuff = (unsigned char *)src;
	if (src == dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		dstbuff[i] = srcbuff[i];
		i++;
	}
	return (dst);
}
