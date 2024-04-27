/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:04:41 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 18:20:57 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static int	check_chars(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

static int	count_sub_strings(char *s, char c)
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
	while (check_chars(s[i], c))
		i++;
	while (s[i] != '\0')
	{
		if (check_chars(s[i], c))
		{
			if (is_sub_string)
				count ++;
			is_sub_string = 0;
		}
		else
		{
			is_sub_string = 1;
		}
		i++;
	}
	if (!check_chars(s[i - 1], c))
		count++;
	return (count);
}

static void free_all(char **str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**results;
	int		split_count;
	int		i;
	int		j;
	int		start;

	if (s == NULL)
		return (NULL);
	split_count = count_sub_strings((char *)s, c);
	results = malloc(sizeof(char *) * (split_count + 1));
	if (results == NULL)
		return (NULL);
	start = 0;
	i = 0;
	j = 0;
	while (i < split_count)
	{
		while (s[j] != '\0' && check_chars(s[j], c))
			j++;
		start = j;
		while (s[j] != '\0' && !check_chars(s[j], c))
			j++;
		results[i] = ft_strndup((char *)&s[start], j - start);
		if (results[i] == NULL)
			free_all(results, i);
		i++;
	}
	results[i] = NULL;
	return (results);
}

// #include <stdio.h>

// int main(void) {
//     char	str[] = "notempty";
//     char	c = '\0';
//     char	**result;
// 	int		split_count = count_sub_strings(str, c);

//     printf ("length is %d\n", split_count);
//     result = ft_split(str, c);

//     for (int i = 0; i < split_count; i++) {
//         printf("%s\n", result[i]);
//     }
//     // Free the dynamically allocated memory
//     for (int i = 0; i < split_count ; i++) {
//         free(result[i]);
//     }
// 	free(result);
//     return 0;
// }

