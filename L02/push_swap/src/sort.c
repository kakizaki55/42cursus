/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/21 17:20:46 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

int sort_two(t_c_list **head, char *stack)
{
	if(is_smaller((*head)->next->content, (*head)->content))
		ft_lstswap(head, stack);
	return (true);
}

int sort_three(t_c_list **head, char *stack)
{
	int i = 0;
	int target = 0;
	if(check_any_sort(*head))
	{
		target = find_nbr(*head, 1);
		while(i++ < target)
			ft_rotate(head, stack);
	}
	else
	{
		ft_lstswap(head, stack);
		target = find_nbr(*head, 1);
		while(i++ < target)
			ft_rotate(head, stack);
	}
	ft_c_print_lst(*head);
	return (true);
}


int short_sort(t_c_list **head, int len)
{	
	//if the length is 1
	if(check_sort(*head) || len == 1)
		return (true);
	//if the length is 2
	if(len == 2)
	{
		sort_two(head, "a");
		return (true);
	}
	// if the the length is 3
	if(len == 3)
	{
		sort_three(head, "a");
		return (true);
	}
	return (false);
}

void sort(t_c_list **head, int len)
{
	t_c_list *stack_a;
	t_c_list *stack_b;

	//initing stacks
	stack_a = *head;
	stack_b = NULL;

	if(!short_sort(head, len))
	{
		puts("here");
	}

	// ft_c_push(&stack_a, &stack_b, "a");

	
	// puts("stack a");
	// ft_c_print_lst(stack_a);
	// puts("stack b");
	// ft_c_print_lst(stack_b);
}