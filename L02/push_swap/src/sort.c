/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/28 16:12:18 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

void split_lsts_long(t_c_list **src, t_c_list **dest, char stack, int dlmt)
{
	int i;
	int index;
	int len;
	char r_stack;

	i = 0;
	index = 0;
	len = (ft_c_lstsize(*src) / 2);
	r_stack = (stack == 'b') ? 'a' : 'b';
	while(i++ <= len)
	{
		if(stack == 'b')
			index = recon_smaller(*src, dlmt);
		else
			index = recon_larger(*src, dlmt);
			
		while(index != 0)
		{
			if(index > 0)
			{	
				ft_rotate(src, r_stack);
				index--;
			}
			else
			{
				ft_r_rotate(src, r_stack);
				index++;
			}
		}
		ft_c_push(src , dest, stack);
	}
}

int find_sortest_path(t_c_list **src, int target_nbr)
{	
	int res;

	res = 0;
	if(is_smaller(find_nbr(*src,target_nbr), find_r_nbr(*src,target_nbr)))
		res = find_nbr(*src,target_nbr);
	else
		res = find_r_nbr(*src, target_nbr) * -1;
	
	return (res);
}

void rotate_stack(t_c_list **src, int stack, int index)
{
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
}

int long_sort(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	//basically need to this function to flip between and b, if it becomes sorted at all then ove on to the next one.
	
	int dlmt;
	int half_way;

	dlmt = ft_c_lstsize(*stack_a) / 2;
	half_way = dlmt;
	split_lsts_long(stack_a, stack_b, 'b', dlmt);
	// puts("-----------");
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');
	while(1)
	{	
		dlmt /= 2;
		printf("dlmt is:%d", dlmt);
		split_lsts_long(stack_b, stack_a, 'a', dlmt);
		if(dlmt <= 3)
			break;
	}
	sort_two_three(stack_b, ft_c_lstsize(*stack_b), 'b');

	// puts("-----------");
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');
	int i = 0;
	int target_nbr = find_max(*stack_b) + 1;
	int index;
	while(i < (half_way * 2))
	{	
		if(target_nbr == (*stack_a)->content)
		{
			ft_c_push(stack_a, stack_b, 'b');
			target_nbr++;
		} else 
		{
			index = find_sortest_path(stack_a, target_nbr);
			// ft_printf("index is:%d\n", index);
			// ft_printf("target number is:%d\n", target_nbr);
			rotate_stack(stack_a, 'a', index);
			ft_c_push(stack_a, stack_b, 'b');
			target_nbr++;
		}
		i++;
	}
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');
	

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
	// int target = 1;
	// int index = 0;

	//initing stacks
	stack_a = *head;
	stack_b = NULL;

	// ft_printf("int is : %d\n", 7/2);


	if(ft_c_lstsize(stack_a) <= 6)
		sort_short(&stack_a, &stack_b, len);
	else 
		long_sort(&stack_a, &stack_b, len);
	// ft_c_print_lst(stack_a, 'a');
	// ft_c_print_lst(stack_b, 'b');
}
