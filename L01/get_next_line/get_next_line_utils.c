/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:17 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/21 18:09:50 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strldup(const char *s, size_t len)
{
	char	*cpy;
	size_t	i;

	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// static size_t	get_smaller(size_t num1, size_t num2)
// {
// 	if (num1 < num2)
// 		return (num1);
// 	if (num1 > num2)
// 		return (num2);
// 	return (num2);
// }

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	char			*res;
// 	unsigned int	i;
// 	size_t			sub_length;

// 	sub_length = 0;
// 	if (s == NULL)
// 		return (NULL);
// 	if (start > ft_strlen(s))
// 		return ("");
// 	while (s[start + sub_length] != '\0')
// 		sub_length++;
// 	i = 0;
// 	res = malloc((get_smaller(sub_length, len) + 1) * sizeof(char));
// 	if (res == NULL)
// 		return (NULL);
// 	while (s[i + start] != '\0' && i < len)
// 	{
// 		res[i] = s[i + start];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }
