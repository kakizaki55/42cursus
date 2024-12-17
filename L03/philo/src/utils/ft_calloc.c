/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:22:53 by mkakizak          #+#    #+#             */
/*   Updated: 2024/12/17 14:54:18 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void print_action(int action)
{
    if(action == 1)
        printf("Eatings");
    if(action == 2)
        printf("Sleeping");
    if(action == 3)
        printf("Thinking");
}

static  void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (n <= 0)
		return ;
	p = s;
	i = 0;
	while (i < n)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return ;
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		free (p);
		return (NULL);
	}
	ft_bzero(p, size * nmemb);
	return (p);
}