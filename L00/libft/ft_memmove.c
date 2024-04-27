/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:21:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:17:18 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstbuff;
	unsigned char	*srcbuff;
	int				i;

	dstbuff = (unsigned char *)dst;
	srcbuff = (unsigned char *)src;
	if (len <= 0)
		return (dst);
	i = 0;
	if (dst < src)
	{
		while (i < (int)len)
		{
			dstbuff[i] = srcbuff[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dstbuff[i] = srcbuff[i];
			i--;
		}
	}
	return (dst);
}
