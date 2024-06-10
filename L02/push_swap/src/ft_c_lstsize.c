/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:06:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/10 13:11:54 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

int	ft_c_lstsize(t_c_list **lst)
{
	int	res;
	t_c_list *current;


	current = *lst;
	// printf("%p\n",&(*lst)); fflush(stdout);
	res = 1;
	while (1)
	{	
		*lst = (*lst)->next;
		printf("prev%p\n",(*lst)->prev); fflush(stdout);
		printf("next%p\n",(*lst)->next); fflush(stdout);
		if(((*lst)->next) == current)
		{
			break ;
		}
		res++;
	}
	return (res);
}
