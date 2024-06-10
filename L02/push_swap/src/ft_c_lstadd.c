/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:56:57 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/10 14:32:17 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

t_c_list	**ft_c_lstadd(t_c_list *new)
{	
	// new->next = &(*lst);
	// printf("head is:%p\n", head);
	// printf("new  is:%p\n", new);
	
	

	if(head == NULL)
	{
		new->next = new;
		new->prev = new;
		return (new);
	}

	t_c_list *last = (*head)->prev;
	
	new->next = head;
	new->prev = last;
	(*head)->prev = new;
	last->next = new;

	return (head);
	// if(new->prev == NULL)
	// {
		
	// 	new->prev = &(*lst);
	// 	*lst = new;
	// printf("new p3 is:%p\n", new->prev);
	// }
	// else
	// {
	// 	new->prev = (*lst)->prev;
	// }
	// // printf("new prev is:%p\n", new->prev);
	// (*lst)->prev = new;
	// *lst = new;
}
