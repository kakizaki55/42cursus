/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/25 17:45:16 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void split_lsts_rc(t_c_list **stack_a, t_c_list **stack_b, char stack)
{
	int i;
	int index;
	int half;

	i = 0;
	index = 0;
	half = stack == 'a' ? ft_c_lstsize(*stack_a) / 2 :ft_c_lstsize(*stack_b) / 2;
	while(i++ < half)
	{
		index = stack == 'a' ? recon(*stack_a, half) : recon_b(*stack_b, half);
		while(index != 0)
		{
			if(index > 0)
			{	
				stack == 'a' ? ft_rotate(stack_a, stack) : ft_rotate(stack_b, stack);
				index--;
			}
			else
			{
				stack == 'a' ? ft_r_rotate(stack_a, stack) : ft_r_rotate(stack_b, stack);
				index++;
			}
		}
		stack == 'a' ? ft_c_push(stack_a, stack_b, 'b') : ft_c_push(stack_b, stack_a, 'a');
	}
}

int long_sort(t_c_list **stack_a, t_c_list **stack_b, int len)
{	
	//basically need to this function to flip between and b, if it becomes sorted at all then ove on to the next one.
	
	split_lsts_rc(stack_a, stack_b, 'a');
	puts("-----------");
	ft_c_print_lst(*stack_a, 'a');
	ft_c_print_lst(*stack_b, 'b');
	split_lsts_rc(stack_a, stack_b, 'b');
	puts("-----------");
	ft_c_print_lst(*stack_a, 'a');
	ft_c_print_lst(*stack_b, 'b');
	return (true);
}

void sort(t_c_list **head, int len)
{
	t_c_list *stack_a;
	t_c_list *stack_b;
	int target = 1;
	int index = 0;

	//initing stacks
	stack_a = *head;
	stack_b = NULL;

	if(sort_short(&stack_a, &stack_b, len))
		// return ;

	// long_sort(&stack_a, &stack_b, len);
	ft_c_print_lst(stack_a, 'a');
	ft_c_print_lst(stack_b, 'b');
}
