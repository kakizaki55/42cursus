/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:16:55 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/30 14:58:21 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

void ft_c_print_lst(t_c_list *head)
{
	t_c_list *current = head;
	int i;

	if(head == NULL)
	{
		ft_printf("List is NULL\n");
		return ;
	}

	i = 0;
    while (1)
	{	
        ft_printf("[%d]:%d\n", i, current->content);
        current = current->next;
		i++;
		if(current == head)
			break;
	}
}

void ft_c_print_elm(t_c_list *elm)
{
	if(elm == NULL)
	{
		ft_printf("List is NULL\n");
		return ;
	}
	ft_printf("[prev]:%d\n", elm->prev->content);
	ft_printf("[content]:%d\n", elm->content);
	ft_printf("[next]:%d\n", elm->next->content);
	return ;
}

int	ft_c_lstsize(t_c_list **lst)
{
	int	res;
	t_c_list *current;

	current = *lst;
	res = 1;
	while (1)
	{	
		*lst = (*lst)->next;
		if(*lst == current)
		{
			return (res);
		}
		res++;
	}
	return (res);
}
