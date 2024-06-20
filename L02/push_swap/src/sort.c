/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:04:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/20 23:50:04 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

// void sort(t_c_list **head, int len)
// {
// 	int target;
// 	target = 1;

// 	while (1)
// 	{	
// 		if((*head)->content == target)
// 		{	
// 			if(target - 1 == (*head)->next->content)
// 			{
// 				ft_lstswap(head);
// 				target++;
// 				ft_rotate(head);
// 				ft_rotate(head);
// 			}
// 			else
// 			{
// 				target++;
// 				ft_rotate(head);
// 			}
// 		}
// 		else if((*head)->content > (*head)->next->content)
// 		{
// 			ft_lstswap(head);
// 			if((*head)->content == target)
// 			{
// 				target++;
// 				ft_rotate(head);
// 			}
// 			else
// 			{
// 				ft_rotate(head);
// 				ft_rotate(head);
// 			}
// 		}
// 		else
// 		{
// 			ft_rotate(head);
// 		}
// 		if(target >= len)
// 		{
// 			if(target == (*head)->next->content)
// 			{
// 				ft_lstswap(head);
// 			}
// 				ft_rotate(head);
// 			break;
// 		}
// 	}
		
// }

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
	//if the the length is 3
	// ft_printf("len is: %d\n", len);
	// if(len == 3)
	// {
	// 	if(check_sort(*head))
	// 		return ;
	// 	int i;
	// 	int nbr;

	// 	i = 0;
	// 	nbr = find_nbr(*head,1);

	// 	while(i < nbr)
	// 	{
	// 		ft_rotate(head, "a");
	// 	}
		
	// }

	//initing stacks
	stack_a = *head;
	stack_b = NULL;

	// ft_c_push(&stack_a, &stack_b, "a");

	
	puts("stack a");
	ft_c_print_lst(stack_a);
	puts("stack b");
	ft_c_print_lst(stack_b);
	
}
