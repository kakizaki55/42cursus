/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/29 22:36:23 by mkakizak         ###   ########.fr       */
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
			// printf("in smaller");
			index = recon_smaller(*src, dlmt);
			if(index == INT_MAX)
			{
				i++;
				break ;
			}
		}
		else
		{
			// printf("in larger");
			index = recon_larger(*src, dlmt);
		}
		
		while(index != 0)
		{
			if(index > 0)
			{	
				ft_rotate(src, src_stack);
				index--;
			}
			else
			{
				ft_r_rotate(src, src_stack);
				index++;
			}
		}
		ft_c_push(src , dest, stack);
	}
}

void split_lsts_large(t_c_list **src, t_c_list **dest, char stack, int dlmt, int chunk_size)
{
    if (!src || !*src || !dest)
        return;

	int i;
	int index;
	int len;
	char src_stack;

	i = 0;
	index = 0;
	src_stack = (stack == 'b') ? 'a' : 'b';
	while(i++ <= chunk_size)
	{
		if(stack == 'b')
		{
			// printf("in smaller i is: %d", i);
			index = recon_smaller(*src, dlmt);
			if(index == INT_MAX)
			{
				i++;
				break ;
			}
		}
		else
		{
			// printf("in larger");
			index = recon_larger(*src, dlmt);
		}

		while(index != 0)
		{
			if(index > 0)
			{	
				ft_rotate(src, src_stack);
				index--;
			}
			else
			{
				ft_r_rotate(src, src_stack);
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
	if(is_smaller(find_nbr(*src, target_nbr), find_r_nbr(*src, target_nbr)))
		res = find_nbr(*src, target_nbr);
	else
		res = find_r_nbr(*src, target_nbr) * -1;
	
	return (res);
}

void rotate_stack(t_c_list **src, int stack, int index)
{
	if (!src || !*src) {
        return;
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
}

void chunk_and_push(t_c_list **stack_a, t_c_list **stack_b, int len)
{
    int chunk_size = len / 20;  // Start with 5 chunks, adjust as needed
    int dlmt = chunk_size + (len / 2);
    
    while (*stack_a != NULL)
    {
        split_lsts_large(stack_a, stack_b, 'b', dlmt, chunk_size);
		// printf("dlmt:%d len: %d", dlmt, len);

        if (dlmt >= len)
		{
			// printf("dlmt:%d len: %d", dlmt, len);
            break;
		}
        
        dlmt += chunk_size;
        if (dlmt > len)
		{
            dlmt = len;
		}
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
	// printf("traget nbr: %dlen is:%d", target_nbr, len);
	while(i < size)
	{
		index = find_sortest_path(stack_b, target_nbr);
		rotate_stack(stack_b, 'b', index);
		ft_c_push(stack_b, stack_a, 'a');
		target_nbr--;
		// printf("i:%d", i);
		i++;
	}
	
}

int long_sort(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	//basically need to this function to flip between and b, if it becomes sorted at all then ove on to the next one.
	
	int dlmt;
	int half_way;

	dlmt = ft_c_lstsize(*stack_a) / 2;
	half_way = dlmt;
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
	sort_two_three(stack_b, ft_c_lstsize(*stack_b), 'b');


	//step 3:
	int i = 0;
	int target_nbr = find_max(*stack_b) + 1;
	int index;
	int b_size = ft_c_lstsize(*stack_b);
	while(i < (len / 2) - b_size)
	{	 
		if(target_nbr == (*stack_a)->content)
		{
			ft_c_push(stack_a, stack_b, 'b');
			target_nbr++;
		} 
		else
		{
			index = find_sortest_path(stack_a, target_nbr);
			rotate_stack(stack_a, 'a', index);
			ft_c_push(stack_a, stack_b, 'b');
			target_nbr++;
		}
		i++;
	}
	
	//step 4;
	chunk_and_push(stack_a, stack_b, len);

	//step 5:
	sort_back(stack_a, stack_b, len);


	// dlmt = half_way;
	// while(*stack_a != NULL)
	// {	
	// 	dlmt += 10;
	// 	printf("dlmt is:%d", dlmt);
	// 	if(dlmt >  len)
	// 		break;
	// 	split_lsts_long(stack_a, stack_b, 'b', dlmt);
	// }
	// ft_printf("here\n");
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');



	//--------------this is where i push it back
	
	// if(!check_sort(*stack_a))
	// {
	// 	ft_r_rotate(stack_a, 'a');
	// 	if(is_bigger((*stack_a)->content, (*stack_a)->next->content))
	// 		ft_lstswap(stack_a, 'a');
	// }

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
