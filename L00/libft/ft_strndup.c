/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:57:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:37:40 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

//this function is not actually in the bonus even tho there is a tester for it. 
#include <stdlib.h>

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		length;
	int		i;

	length = n;
	dest = (char *)malloc((length +1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
