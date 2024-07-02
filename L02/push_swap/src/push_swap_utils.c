/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:23:36 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/02 14:13:14 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_c_list	*ft_c_lstnew(int content)
{
	t_c_list	*node;

	node = (t_c_list *) ft_calloc(sizeof(t_c_list), 1);
	if (node == NULL)
	{
		error();
	}
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_c_push(t_c_list **src, t_c_list **dest, char stack)
{	
	ft_c_lstadd(dest, ft_lstpop(src));
	ft_printf("p%c\n", stack);
}

void	ft_c_lstadd(t_c_list **head, t_c_list *new)
{	
	t_c_list *last;

	if (!new)
		return ;
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}
	last = (*head)->prev;
	new->next = *head;
	new->prev = last;
	(*head)->prev = new;
	last->next = new;
	*head = new;
}

t_c_list	*ft_lstpop(t_c_list **head)
{
	t_c_list	*popped;

	if (!head || !*head)
		return (NULL);
	popped = *head;
	if (popped->next == popped)
	{
		*head = NULL;
	}
	else
	{
		popped->prev->next = popped->next;
		popped->next->prev = popped->prev;
		*head = popped->next;
	}
	popped->next = popped;
	popped->prev = popped;
	return (popped);
}

int	ft_c_lstsize(t_c_list *lst)
{
	int	res;
	t_c_list	*current;

	if (!lst)
		return (0);
	current = lst;
	res = 1;
	while (1)
	{	
		lst = lst->next;
		if (lst == current)
			return (res);
		res++;
	}
	return (res);
}

void	ft_rotate(t_c_list **head, char stack)
{
	*head = (*head)->next;
	ft_printf("r%c\n", stack);
}

void ft_r_rotate(t_c_list **head, char stack)
{
	*head = (*head)->prev;
	ft_printf("rr%c\n", stack);
}

void rotate_stack(t_c_list **src, int stack, int index)
{
	if (!src || !*src)
		return ;
	while (index != 0)
	{
		if (index > 0)
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

void	ft_lstswap(t_c_list **head, char stack)
{
	int	temp;

	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	ft_printf("s%c\n", stack);
}

void ft_c_lstclear(t_c_list **head)
{
	t_c_list	*current;
	t_c_list	*next;	

	current = (*head)->next;
	if (*head == NULL)
		return ;
	while (current != *head)
	{
		next = current->next;
		free(current);
		current = next;
	}	
	free(*head);
	*head = NULL;
}

void	ft_c_lstiter(t_c_list *head, int (*f)(int))
{
	t_c_list	*current;

	current = head;
	while (1)
	{	
		current->content = f(current->content);
		current = current->next;
		if (current == head)
			break ;
	}
}

void	ft_c_print_lst(t_c_list *head, char stack)
{
	t_c_list	*current;
	int			i;

	current = head;
	if (head == NULL)
	{
		ft_printf("List [%c]is NULL\n", stack);
		return ;
	}
	i = 0;
	while (1)
	{
		if (i == 0)
		{
			ft_printf("[%d]:%d<-head[%c]\n", i, current->content, stack);
		}
		else
		{
			ft_printf("[%d]:%d\n", i, current->content);
		}
			current = current->next;
		i++;
		if (current == head)
			break ;
	}
}
