/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:31:51 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/02 13:49:04 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

// #include <string.h>
// int main(void)
// {
// 	// int f1 = ft_strncmp(NULL, "hello", 0);
// 	int f1 = ft_strncmp(NULL, "nope", 0);
// 	// int f2 = strncmp((void *)0, "nope", 0);
// 	// int f2 = strncmp(NULL, "hello", 1);

// 	printf("ft is: %d \n", f1);
// 	// printf("ft is: %p \n", (void *)0);
// 	// printf("ft is: %p \n", NULL);
// 	// printf("strncmp is: %d \n", f2);
// } 
