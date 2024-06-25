/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/25 13:29:31 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int sort_two(t_c_list **head, char *stack)
{
	if((stack == "b") && is_smaller((*head)->content, (*head)->next->content))
		ft_lstswap(head, stack);
	if(stack == "a" && is_smaller((*head)->next->content, (*head)->content))
		ft_lstswap(head, stack);
	return (true);
}

int sort_three(t_c_list **head,int target_nbr, char *stack)
{
	int i = 0;
	int target = 0;
	if(check_any_sort(*head) && stack == "a")
	{
		target = find_nbr(*head, target_nbr);
		while(i++ < target)
			ft_rotate(head, stack);
	}
	else if(stack == "a")
	{
		ft_lstswap(head, stack);
		// ft_c_print_lst(*head);
		target = find_nbr(*head, target_nbr);
		while(i++ < target)
			ft_rotate(head, stack);
	}
	if(check_any_r_sort(*head) && stack == "b")
	{
		target = find_nbr(*head, target_nbr);
		while(i++ < target)
			ft_rotate(head, stack);
	}
	else if(stack == "b")
	{
		ft_lstswap(head, stack);
		// ft_c_print_lst(*head);
		target = find_nbr(*head, target_nbr);
		while(i++ < target)
			ft_rotate(head, stack);
	}

	return (true);
}

int recon(t_c_list *head, int half)
{
	int i;
	int index;
	int r_index;
	t_c_list *temp;
	t_c_list *r_temp;
	int lst_size = ft_c_lstsize(head);

	i = 0;
	index = 0;
	r_index = 0;
	temp = head;
	r_temp = head;
	while (i < lst_size)
	{
		if(temp->content <= half)
			return (index);
		temp = temp->next;
		index ++;
		if(r_temp->content <= half)
			return (r_index);
		r_temp = r_temp->prev;
		r_index--;
		i++;
	}
	return (0);
}

int sort_two_three(t_c_list **head, int len, char *stack)
{
	int smallest;
	int largest;
	smallest = find_min(*head);
	largest = find_max(*head);

	if(len == 2)
	{
		sort_two(head, stack);
		// return (true);
	}
	if(len == 3)
	{
		if(stack == "a")
			sort_three(head, smallest, stack);
		if(stack == "b")
			sort_three(head, largest, stack);
		// return (true);
	}
	return (true);
}

void split_lsts(t_c_list **stack_a, t_c_list **stack_b, int half)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while(i++ < half)
	{
		index = recon(*stack_a, half);
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
		ft_c_push(stack_a, stack_b, "b");
	}
}

void push_all(t_c_list **src_lst, t_c_list **dest_lst)
{
	int i = 0;

	int b_size = ft_c_lstsize(*src_lst);
	while (i < b_size)
	{
		ft_c_push(src_lst, dest_lst, "a");
		i++;
	}
	*src_lst = NULL;
}

int sort_six(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	int i;
	int index;
	int half;

	i = 0;
	half = ft_c_lstsize(*stack_a) / 2;
	split_lsts(stack_a, stack_b, half);
	sort_two_three(stack_a, ft_c_lstsize(*stack_a), "a");
	sort_two_three(stack_b, ft_c_lstsize(*stack_b), "b");
	push_all(stack_b, stack_a);
	return (true);
}

int sort_short(t_c_list **stack_a, t_c_list **stack_b, int len)
{	
	if(check_sort(*stack_a))
		return (true);
	if(len <= 3)
	{
		sort_two_three(stack_a, len, "a");
		return (true);
	}
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

	ft_c_print_lst(stack_a, "a");
	ft_c_print_lst(stack_b, "b");

	// ft_c_push(&stack_a, &stack_b, "a");

	
	// puts("stack a");
	// ft_c_print_lst(stack_a);
	// puts("stack b");
	// ft_c_print_lst(stack_b);
}