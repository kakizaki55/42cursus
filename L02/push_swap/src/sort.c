/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/21 18:33:27 by mkakizak         ###   ########.fr       */
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
		if(nbr < temp->content)
			return (index);
		temp = temp->next;
		index ++;
		if(nbr < r_temp->content)
			return (r_index);
		r_temp = r_temp->prev;
		r_index--;
		i++;
	}
	return (0);
}

int sort_six(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	int i;
	i = 0;
	if((*stack_a)->content >= len / 2)
	{

		ft_c_push(stack_a, stack_b, "a");
		ft_c_print_lst(*stack_a);
		ft_c_print_lst(*stack_b);
		ft_printf("recon returns:%d\n", recon(*stack_a, (len / 2)));

	}
}


int sort_short(t_c_list **stack_a, t_c_list **stack_b, int len)
{	
	//if the length is 1
	if(check_sort(*stack_a) || len == 1)
		return (true);
	//if the length is 2
	if(len == 2)
	{
		sort_two(stack_a, "a");
		return (true);
	}
	// if the the length is 3
	if(len == 3)
	{
		sort_three(stack_a, "a");
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