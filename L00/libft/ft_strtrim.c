/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:28:50 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:36:52 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include "libft.h"

// static char	*ft_strchr(const char *s, int c)
// {
// 	int	stringlength;
// 	int	i;

// 	i = 0;
// 	stringlength = ft_strlen(s);
// 	while (i < stringlength + 1)
// 	{
// 		if (s[i] == (char)c)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// static void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*p;

// 	if (n <= 0)
// 		return ;
// 	p = s;
// 	while (n > 0)
// 	{
// 		*p = 0;
// 		p++;
// 		n--;
// 	}
// 	return ;
// }

// static char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*res;
// 	unsigned int	i;

// 	if (s == NULL)
// 		return (NULL);
// 	i = 0;
// 	res = malloc((len + 1) * sizeof(char));
// 	if (res == NULL)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (res);
// 	ft_bzero(res, len);
// 	while (s[i] != '\0' && i < len)
// 	{
// 		res[i] = s[i + start];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	res = ft_substr(s1, 0, i + 1);
	return (res);
}

// int mian(void)
// {
// 	char string[] = "abcdefg";
// 	ft_strtrim(string, "ab");
// }
