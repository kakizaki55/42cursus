/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:04:41 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 14:26:56 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	check_chars(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

static char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		length;
	int		i;

	length = n;
	//  need to clean up all memmro if allocation fails
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

static int	count_sub_strings(char *s, char c)
{
	int	i;
	int	count;
	int	is_sub_string;

	is_sub_string = 0;
	count = 0;
	i = 0;
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
	if (!check_chars(s[i], c) && count == 0)
		count = 1;
	return (count);
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
	results = malloc(sizeof(char *) * (split_count));
	if (results == NULL)
		return (NULL);
	// need to add a NULL to end of double pointer
	if (c == '\0')
	{
		results[0] = NULL;
		return (results);
	}
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
		i++;
	}
	return (results);
}

// #include <stdio.h>

// int main() {
//    char str[] = "      split       this for   me  !       ";
//     char c = ' ';
//     char **result;

// 	int split_count = count_sub_strings(str, c);


//     printf("length is %d\n", split_count);

//     result = ft_split(str, c);

//     for (int i = 0; i < split_count; i++) {
//         printf("%s\n", result[i]);
//     }

//     // Free the dynamically allocated memory
//     for (int i = 0; i < split_count ; i++) {
//         free(result[i]);
//     }
//     free(result);

//     return 0;
// }
