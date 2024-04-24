/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:14 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/24 13:07:37 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	if(s1 == NULL || s2 == NULL)
		return (NULL);
	char * res;
	int i;
	int j;

	i = 0;
	j = 0;
	res = malloc((ft_strlen((char *)s2) + ft_strlen((char *)s1) + 1) * sizeof(char));
	if(res == NULL)
		return(res);

	while(s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while(s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return(res);
	
}