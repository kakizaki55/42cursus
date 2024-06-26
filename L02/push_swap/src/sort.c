/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/26 18:45:37 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void split_lsts_long(t_c_list **src, t_c_list **dest, char stack, int dlmt)
{
	int i;
	int index;
	int len;

	i = 0;
	index = 0;
	len = ft_c_lstsize(*src) / 2;
	while(i++ < len)
	{
		if(stack == 'a')
		{
			index = recon(*src, dlmt);
		} 
		else
		{
			puts("heres");
			index = recon_b(*src, dlmt);
		}
			
		while(index != 0)
		{
			if(index > 0)
			{	
				ft_rotate(src, stack);
				index--;
			}
			else
			{
				ft_r_rotate(src, stack);
				index++;
			}
		}
		ft_c_push(src , dest, stack);
	}
}

void recursive_split(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	
}

int long_sort(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	//basically need to this function to flip between and b, if it becomes sorted at all then ove on to the next one.
	

	int dlmt;

	dlmt = ft_c_lstsize(*stack_a) / 2;
	split_lsts_long(stack_a, stack_b, 'a', dlmt);
	dlmt /= 2;
	puts("-----------");
	ft_c_print_lst(*stack_a, 'a');
	ft_c_print_lst(*stack_b, 'b');
	while(ft_c_lstsize(*stack_b) > 3)
	{	
		printf("dlmt is:%d", dlmt);
		split_lsts_long(stack_b, stack_a, 'b', dlmt);
		dlmt /= 2;	
	}

	sort_two_three(stack_b, ft_c_lstsize(*stack_b), 'b');
	puts("-----------");
	ft_c_print_lst(*stack_a, 'a');
	ft_c_print_lst(*stack_b, 'b');

	// int i = 0;
	// int len = ft_c_lstsize(*stack_a);
	// recursive_split(stack_a, stack_b, len);

	

	// while(1)
	// {
		// if(ft_c_lstsize(*stack_b) <= 3)
		// 	sort_two_three(stack_b,ft_c_lstsize(*stack_b), 'b');
		// if(ft_c_lstsize(*stack_a) <= 3)
		// 	sort_two_three(stack_a,ft_c_lstsize(*stack_a), 'a');

		// split_lsts_rc(stack_a, stack_b, 'a');
		// split_lsts_rc(stack_b, stack_a, 'b');
	// }

	
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');

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
		return ;

	long_sort(&stack_a, &stack_b, len);
	// ft_c_print_lst(stack_a, 'a');
	// ft_c_print_lst(stack_b, 'b');
}
