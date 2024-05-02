/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:21:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/02 14:24:35 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	move_front(unsigned char*dest, unsigned char*ssrc, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		dest[i] = ssrc[i];
		i++;
	}
}

static	void	move_back(unsigned char *dest, unsigned char*ssrc, size_t len)
{
	int	i;

	i = (int)len - 1;
	while (i >= 0)
	{
			dest[i] = ssrc[i];
			i--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstbuff;
	unsigned char	*srcbuff;

	dstbuff = (unsigned char *)dst;
	srcbuff = (unsigned char *)src;
	if (len <= 0)
		return (dst);
	if (dst < src)
	{
		move_front(dstbuff, srcbuff, len);
	}
	else if (dst > src)
	{
		move_back(dstbuff, srcbuff, len);
	}
	return (dst);
}
