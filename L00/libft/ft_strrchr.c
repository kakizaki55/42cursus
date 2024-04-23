/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:13 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/23 14:07:41 by mkakizak         ###   ########.fr       */
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

 char * ft_strrchr(const char *s, int c)
 {
	int i;
	
	char * res;

	i = 0;
	res = NULL;

	while (i <= (int)ft_strlen(s))
	{
		if(s[i] == (char)c)
		{
			res = (char *)&s[i];
		}
		i++;
	}
	return (res);
 }
 