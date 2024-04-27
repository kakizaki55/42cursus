/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:56:33 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:09:25 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (n <= 0)
		return ;
	p = s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
	return ;
}
