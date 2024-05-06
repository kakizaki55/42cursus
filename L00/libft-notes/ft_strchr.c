/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:12:41 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/02 14:29:58 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	stringlength;
	int	i;

	i = 0;
	stringlength = ft_strlen(s);
	while (i < stringlength + 1)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int    main(void)
// {
//     char str[] = "trip0ouille";
//     printf("%s\n", ft_strchr(str, 48));
//     printf("%s\n", strchr(str, 48));
//     return (0);
// }
