/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/22 00:45:06 by mkakizak         ###   ########.fr       */
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

int sort_three(t_c_list **head,int smallest, char *stack)
{
	int i = 0;
	int target = 0;
	if(check_any_sort(*head))
	{
		target = find_nbr(*head, smallest);
		while(i++ < target)
			ft_rotate(head, stack);
	}
	else
	{
		// ft_c_print_lst(*head);
		ft_lstswap(head, stack);
		ft_c_print_lst(*head);
		target = find_nbr(*head, smallest);
		while(i++ < target)
			ft_rotate(head, stack);
	}
	return (true);
}

int recon(t_c_list *head, int nbr)
{
	int i;
	int index;
	int r_index;
	t_c_list *temp;
	t_c_list *r_temp;

	i = 0;
	index = 0;
	r_index = 0;
	temp = head;
	r_temp = head;
	while (i <= nbr)
	{
		if(temp->content > nbr)
			return (index);
		temp = temp->next;
		index ++;
		if(r_temp->content > nbr)
			return (r_index);
		r_temp = r_temp->prev;
		r_index--;
		i++;
	}
	return (0);
}

int sort_small(t_c_list **head, int len, char *stack)
{
	int smallest;
	smallest = find_min(*head);
	if(check_sort(*head) || len == 1)
		return (true);
	//if the length is 2
	if(len == 2)
	{
		sort_two(head, stack);
		return (true);
	}
	// if the the length is 3
	if(len == 3)
	{
		sort_three(head, smallest, stack);
		return (true);
	}
}


int sort_six(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	int index;
	int half;

	half = len / 2;
	while(ft_c_lstsize(*stack_a) > half )
	{
		index = recon(*stack_a, (half));
		while(index != 0)
		{
			if(index > 0)
			{
				ft_rotate(stack_a, "a");
				index--;
			}
			else
			{
				ft_r_rotate(stack_a, "a");
				index++;
			}
		}
		ft_c_push(stack_a, stack_b, "a");
	}
	puts("checking here:\n");
	ft_c_print_lst(*stack_a);
	ft_c_print_lst(*stack_b);
	sort_small(stack_a, ft_c_lstsize(*stack_a), "a");
	sort_small(stack_b, ft_c_lstsize(*stack_b), "b");
	puts("checking here:\n");
	ft_c_print_lst(*stack_a);
	ft_c_print_lst(*stack_b);
	
	return (true);
}


int sort_short(t_c_list **stack_a, t_c_list **stack_b, int len)
{	
	//if the length is 1 to 3
	if(len <= 3)
	{
		sort_small(stack_a, len, "a");
		ft_c_print_lst(*stack_a);
		return (true);
	}
	// if the lenth is 6 or under
	if(len <= 6)
	{
		sort_six(stack_a, stack_b, len);
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

	if(!sort_short(&stack_a, &stack_b, len))
	{
		puts("here");
	}

	// ft_c_push(&stack_a, &stack_b, "a");

	
	// puts("stack a");
	// ft_c_print_lst(stack_a);
	// puts("stack b");
	// ft_c_print_lst(stack_b);
}