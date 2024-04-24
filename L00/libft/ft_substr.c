/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:05:34 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/24 13:06:59 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (n <= 0)
		return ;
	p = s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
	return ;
}

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
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char * res;
	unsigned int i;
	if(s == NULL)
		return (NULL);

	i = 0;
	res = malloc((len + 1) * sizeof(char));

	if(res == NULL)
		return (NULL);
		
	if(start >= ft_strlen(s))
		return (res);
		
	ft_bzero(res, len);

	while(s[i] != '\0' && i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	
	return(res);	
}

// int main(void)
// {
// 	char str[] = "i just want this part #############";
// 	size_t size = 20;

// 	char *ret1 = ft_substr(str, 5, size);
// 	// char *ret2 = substr(str, 5, size);


// 	printf("ft: %s", ret1);
// 	// printf("og: %s", ret2);
	
// }