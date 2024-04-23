/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:12:41 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/23 16:11:05 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

 char * ft_strchr(const char *s, int c)
 {
	int stringlength;
	int i;

	i = 0;
	stringlength = ft_strlen(s);
	while (i < stringlength + 1)
	{
		if(s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
 }

#include <stdio.h>
#include <string.h>
int    main(void)
{
    char str[] = "tripouille";

    printf("%s\n", ft_strchr(str, 0));
    printf("%s\n", strchr(str, 0));
    return (0);
}
 
