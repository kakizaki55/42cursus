/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:04:41 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/24 19:27:07 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		length;
	int		i;

	length = n;
	dest = (char *)malloc((sizeof(char) * (length + 1)));
	if (!dest)
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

static int	count_sub_strings(char *s, char c )
{
	int	i;
	int	count;
	int	is_sub_string;

	is_sub_string = 0;
	count = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count += is_sub_string;
			is_sub_string = 0;
		}
		else
			is_sub_string = 1;
		i++;
	}
	return (!(s[i - 1] == c) + count);
}

static void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*get_next_string(char *str, char chr, int *start)
{
	char	*substr;
	int		end;

	while (str[*start] && (str[*start] == chr))
		(*start)++;
	end = *start;
	while (str[end] && !(str[end] == chr))
		end++;
	substr = ft_strndup(str + *start, end - *start);
	if (substr == NULL)
		return (NULL);
	*start = end;
	return (substr);
}

char	**cmd_split(char const *s, char c)
{
	char	**results;
	int		split_count;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	split_count = count_sub_strings((char *)s, c);
	results = (char **)malloc(sizeof(char *) * (split_count + 1));
	if (results == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (i < split_count)
	{
		results[i] = get_next_string((char *)s, (char)c, &start);
		if (results[i] == NULL)
		{
			free_all(results);
			return (NULL);
		}
		i++;
	}
	results[i] = NULL;
	return (results);
}
