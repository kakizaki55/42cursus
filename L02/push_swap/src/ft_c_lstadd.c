/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:56:57 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/09 23:30:16 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

void	ft_c_lstadd(t_c_list **lst, t_c_list *new)
{	
	// printf("new p1 is:%p\n", new->next);
	new->next = *lst;
	printf("new next is:%p\n", new->next);
	// printf("new p3 is:%p\n", new->prev);
	if((*lst)->prev == NULL)
	{
		new->prev = *lst;
	}
	else
	{
		new->prev = (*lst)->prev;
	}
	printf("new prev is:%p\n", new->prev);
	(*lst)->prev = new;
	*lst = new;
}
