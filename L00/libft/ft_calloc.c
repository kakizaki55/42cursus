/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:05:59 by mkakizak          #+#    #+#             */
/*   Updated: 2023/01/01 09:24:31 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
// int check_overflow(size_t nmemb, size_t size)
// {
// 	size_t check;

// 	check = 1;
// 	check = (nmemb * size);

// 	if (check != nmemb / size)
// 		return (0);
// 	return (1);
// }

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	// if (check_overflow(nmemb, size))
	// 	return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
	{
		free (p);
		return (NULL);
	}
	ft_bzero(p, size * nmemb);
	return (p);
}
// int main(void)
// {	
// 	int size = 10;

// 	void * d1 = ft_calloc(size, sizeof(int));
// 	void * d2 = calloc(size, sizeof(int));

// 	printf("calloc: %p \n", d1);
// 	// printf("calloc: %lu", d1[0]);
// 	printf("ft_calloc: %p \n", d2);
// 	// printf("ft_calloc: %lu", d2[0]);

// 	free(d1);
// 	free(d2);

// 	return(0);
// }
