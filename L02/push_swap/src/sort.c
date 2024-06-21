/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/21 15:42:20 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

void short_sort(t_c_list **head, int len)
{	
	t_c_list *stack_a;
	t_c_list *stack_b;
	
	//if the length is 1
	if(check_sort(*head) || len == 1)
		return ;
	//if the length is 2
	if(len == 2)
	{
		if(is_smaller((*head)->next->content, (*head)->content))
			return (ft_lstswap(head, "a"));
		else 
			return ;
	}
	// if the the length is 3
	ft_printf("len is: %d\n", len);

	int i = 0;
	int target = 0;
	if(len == 3)
	{
		if(check_any_sort(*head))
		{
			target = find_nbr(*head, 1);
			while(i++ < target)
				ft_rotate(head, "a");
		}
		else
		{
			ft_lstswap(head, "a");
			target = find_nbr(*head, 1);
			while(i++ < target)
				ft_rotate(head, "a");
		}	
		return ;
	}

	//initing stacks
	stack_a = *head;
	stack_b = NULL;

	// ft_c_push(&stack_a, &stack_b, "a");

	
	puts("stack a");
	ft_c_print_lst(stack_a);
	puts("stack b");
	ft_c_print_lst(stack_b);
	
}
