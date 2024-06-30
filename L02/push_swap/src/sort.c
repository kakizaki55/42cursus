/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/30 19:12:16 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

void split_lsts_small(t_c_list **src, t_c_list **dest, char stack, int dlmt)
{
	int i;
	int index;
	int len;
	char src_stack;

	i = 0;
	index = 0;
	len = (ft_c_lstsize(*src) / 2);
	src_stack = (stack == 'b') ? 'a' : 'b';
	while(i++ <= len)
	{
		if(stack == 'b')
		{
			index = recon_smaller(*src, dlmt);
			if(index == INT_MAX)
			{
				i++;
				break ;
			}
		}
		else
			index = recon_larger(*src, dlmt);
		rotate_stack(src, src_stack, index);
		ft_c_push(src , dest, stack);
	}
}

void split_lsts_large(t_c_list **src, t_c_list **dest, char stack, int dlmt, int chunk_size)
{
	int i;
	int index;
	char src_stack;

	i = 0;
	index = 0;
	src_stack = (stack == 'b') ? 'a' : 'b';
	while(i++ <= chunk_size)
	{
		if(stack == 'b')
		{
			index = recon_smaller(*src, dlmt);
			if(index == INT_MAX)
			{
				i++;
				break ;
			}
		}
		else
			index = recon_larger(*src, dlmt);

		rotate_stack(src, src_stack, index);
		ft_c_push(src , dest, stack);
	}
}

int find_sortest_path(t_c_list **src, int target_nbr)
{	
	int res;

	res = 0;
	if(is_smaller(find_nbr(*src, target_nbr), find_r_nbr(*src, target_nbr)))
		res = find_nbr(*src, target_nbr);
	else
		res = find_r_nbr(*src, target_nbr) * -1;
	
	return (res);
}

void chunk_and_push(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	//this is where i will be doing chunk minupulations:
    int chunk_size = len / 10; 
	if(chunk_size == 0)
		chunk_size = 5;
    int dlmt = chunk_size;
    
    while (*stack_a != NULL)
    {
        split_lsts_large(stack_a, stack_b, 'b', dlmt, chunk_size);
        if (dlmt >= len)
            break;

        
        dlmt += chunk_size;
        if (dlmt > len)
        	dlmt = len;
    }
}

void sort_back(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	int i;
	int target_nbr;
	int index;
	int size;

	i = 0;
	target_nbr = find_max(*stack_b);
	size = ft_c_lstsize(*stack_b);
	while(i < size)
	{
		index = find_sortest_path(stack_b, target_nbr);
		rotate_stack(stack_b, 'b', index);
		ft_c_push(stack_b, stack_a, 'a');
		target_nbr--;
		i++;
	}
	
}

int long_sort(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	
	int dlmt;

	dlmt = ft_c_lstsize(*stack_a) / 2;
	//step one:
	split_lsts_small(stack_a, stack_b, 'b', dlmt);
	//step two:
	while(1)
	{	
		dlmt /= 2;
		split_lsts_small(stack_b, stack_a, 'a', dlmt);
		if(dlmt <= 3)
			break;
	}
	
	//step 3;
	chunk_and_push(stack_a, stack_b, len);

	//step 4:
	sort_back(stack_a, stack_b, len);
	return (true);
}

void sort(t_c_list **head, int len)
{
	t_c_list *stack_a;
	t_c_list *stack_b;

	//initing stacks
	stack_a = *head;
	stack_b = NULL;

	if(ft_c_lstsize(stack_a) <= 6)
		sort_short(&stack_a, &stack_b, len);
	else 
		long_sort(&stack_a, &stack_b, len);
	ft_c_print_lst(stack_a, 'a');
	ft_c_print_lst(stack_b, 'b');
	ft_c_lstclear(&stack_a);
	ft_c_lstclear(&stack_b);
	
}
