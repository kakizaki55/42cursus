/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:46:10 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/29 10:32:34 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

int sort_two(t_c_list **head, char stack)
{
	if((stack == 'b') && is_smaller((*head)->content, (*head)->next->content))
		ft_lstswap(head, stack);
	if(stack == 'a' && is_smaller((*head)->next->content, (*head)->content))
		ft_lstswap(head, stack);
	return (true);
}

int sort_three(t_c_list **head,int target_nbr, char stack)
{
	int i = 0;
	int target_index = 0;
	int is_sorted;
	
	// ft_printf("target nbr: %d\n", target_nbr);

	is_sorted = (stack == 'a') ? check_any_sort(*head) : check_any_r_sort(*head);

	if(!is_sorted)
		ft_lstswap(head, stack);

	if(is_smaller(find_nbr(*head,target_nbr), find_r_nbr(*head,target_nbr)))
		target_index = find_nbr(*head,target_nbr);
	else
		target_index = find_r_nbr(*head, target_nbr) * -1;

		// ft_printf("target index: %d\n", target_index);
		while(target_index != 0)
		{
			if(target_index > 0)
			{
				ft_rotate(head, stack);
				target_index--;
			}
			else
			{
				ft_r_rotate(head, stack);
				target_index++;
			}
		}
	return (true);
}

int sort_two_three(t_c_list **head, int len, char stack)
{
	int smallest;
	int largest;
	smallest = find_min(*head);
	largest = find_max(*head);

	// ft_printf("largest is: ",largest);
	// ft_printf("size is: ",ft_c_lstsize(*head));

	// if((largest == ft_c_lstsize(*head)) && (smallest == 1))
	// 	return (false);

	if(len == 2)
	{
		sort_two(head, stack);
	}
	if(len == 3)
	{
		if(stack == 'a')
		{
			sort_three(head, smallest, stack);
		}
		if(stack == 'b')
		{
			sort_three(head, largest, stack);
		}
	}
	return (true);
}

void split_lsts(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	int i;
	int index;
	int half;

	i = 0;
	index = 0;
	half = ft_c_lstsize(*stack_a) / 2;
	printf("half is:%d", half);
	while(i++ < half)
	{
		index = recon_smaller(*stack_a, half);
		printf("index is:%d", index);
		while(index != 0)
		{
			if(index > 0)
			{
				ft_rotate(stack_a, 'a');
				index--;
			}
			else
			{
				ft_r_rotate(stack_a, 'a');
				index++;
			}
		}
		ft_c_push(stack_a, stack_b, 'b');
	}
}

int sort_six(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	int i;
	int index;

	i = 0;
	split_lsts(stack_a, stack_b, len);
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');
	sort_two_three(stack_a, ft_c_lstsize(*stack_a), 'a');
	sort_two_three(stack_b, ft_c_lstsize(*stack_b), 'b');
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');
	push_all(stack_b, stack_a, 'a');
	// printf("check sort: %d", check_sort(*stack_a));
	return (true);
}

int sort_short(t_c_list **stack_a, t_c_list **stack_b, int len)
{	
	// printf("check sort: %d", check_sort(*stack_a));

	if(check_sort(*stack_a))
		return (true);
	if(len <= 3)
	{
		sort_two_three(stack_a, len, 'a');
		return (true);
	}
	if(len <= 6)
	{
		sort_six(stack_a, stack_b, len);
		return (true);
	}
	return (false);
}
