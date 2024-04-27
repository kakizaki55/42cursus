/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:56:33 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 15:33:52 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (n <= 0)
		return ;
	p = s;
	i = 0;
	while (i < n)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return ;
}
