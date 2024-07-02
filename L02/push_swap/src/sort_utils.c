/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:58:06 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/02 19:38:50 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_sort(t_c_list *head)
{
	int			i;
	t_c_list	*current;

	i = find_min(head);
	current = head;
	while (1)
	{	
		if (current->content == i)
		{
			current = current->next;
			i++;
		}
		else
		{
			return (FALSE);
		}
		if (current == head)
			return (TRUE);
	}
	return (FALSE);
}

int	check_r_sort(t_c_list *head)
{
	int			i;
	t_c_list	*current;

	i = ft_c_lstsize(head);
	current = head;
	while (1)
	{	
		if (current->content == i)
		{
			i--;
			current = current->next;
		}
		else
		{
			return (FALSE);
		}
		if (current == head)
			return (TRUE);
	}
	return (FALSE);
}

int	find_nbr(t_c_list *head, int nbr)
{
	int			i;
	t_c_list	*current;

	if (head == NULL || nbr == 0)
		return (FALSE);
	i = 0;
	current = head;
	while (1)
	{
		if (current->content != nbr)
		{
			i++;
			current = current->next;
		}
		else
		{
			return (i);
		}
		if (current == head)
			return (FALSE);
	}
	return (FALSE);
}

int	find_r_nbr(t_c_list *head, int nbr)
{
	int			i;
	t_c_list	*current;

	if (head == NULL || nbr == 0)
		return (FALSE);
	i = 0;
	current = head;
	while (1)
	{	
		if (current->content != nbr)
		{
			i++;
			current = current->prev;
		}
		else
		{
			return (i);
		}
		if (current == head)
			return (FALSE);
	}
	return (FALSE);
}

int	check_any_sort(t_c_list *head)
{
	int	size;
	int	i;

	i = 0;
	size = ft_c_lstsize(head);
	while (i < size)
	{
		if (check_sort(head))
			return (TRUE);
		head = head->next;
		i++;
	}
	if (check_sort(head))
		return (TRUE);
	else
		return (FALSE);
}

// void	ft_c_print_lst(t_c_list *head, char stack)
// {
// 	t_c_list	*current;
// 	int			i;

// 	current = head;
// 	if (head == NULL)
// 	{
// 		ft_printf("List [%c]is NULL\n", stack);
// 		return ;
// 	}
// 	i = 0;
// 	while (1)
// 	{
// 		if (i == 0)
// 		{
// 			ft_printf("[%d]:%d<-head[%c]\n", i, current->content, stack);
// 		}
// 		else
// 		{
// 			ft_printf("[%d]:%d\n", i, current->content);
// 		}
// 			current = current->next;
// 		i++;
// 		if (current == head)
// 			break ;
// 	}
// }
