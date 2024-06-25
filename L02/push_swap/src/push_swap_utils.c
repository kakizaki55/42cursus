/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:23:36 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/14 11:56:07 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

t_c_list	*ft_c_lstnew(int content)
{
	t_c_list	*node;

	node = (t_c_list *) ft_calloc(sizeof(t_c_list), 1);
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void ft_c_push(t_c_list **src, t_c_list **dest, char *stack)
{
	ft_c_lstadd(dest, ft_lstpop(src));
	ft_printf("p%s\n", stack);
}

void	ft_c_lstadd(t_c_list **head, t_c_list *new)
{	
	if(*head == NULL)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}

	t_c_list *last = (*head)->prev;
	
	new->next = *head;
	new->prev = last;
	(*head)->prev = new;
	last->next = new;
	*head = new;
} 

t_c_list *ft_lstpop(t_c_list **head)
{
	t_c_list *popped; 
	t_c_list *temp;

	temp = *head;
	popped = ft_c_lstnew((*head)->content);
	(*head)->prev->next = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	*head = (*head)->next;
	free(temp);
	popped->next = popped;
	popped->prev = popped;
	return (popped);
}

int	ft_c_lstsize(t_c_list *lst)
{
	int	res;
	t_c_list *current;

	current = lst;
	res = 1;
	while (1)
	{	
		lst = lst->next;
		if(lst == current)
		{
			return (res);
		}
		res++;
	}
	return (res);
}

void ft_c_print_lst(t_c_list *head, char *stack)
{
	t_c_list *current = head;
	int i;

	if(head == NULL)
	{
		ft_printf("List [%s]is NULL\n", stack);
		return ;
	}

	i = 0;
    while (1)
	{	
		if(i == 0)
		{
        	ft_printf("[%d]:%d<-head[%s]\n", i, current->content, stack);
		}
		else
		{
        	ft_printf("[%d]:%d\n", i, current->content);
		}
        current = current->next;
		i++;
		if(current == head)
			break;
	}
}

void ft_rotate(t_c_list **head, char *stack)
{
	*head = (*head)->next;
	ft_printf("r%s\n", stack);

}

void ft_r_rotate(t_c_list **head, char *stack)
{
	*head = (*head)->prev;
	ft_printf("rr%s\n", stack);

}

void ft_c_lstclear(t_c_list **head)
{
	t_c_list *current = *head;
	int i = 0;

    while (1)
	{	
        current = current->next;
		if(current->next == *head)
		{
			free(current);
			break;
		}
		else
		{
			free(current->prev);
		}
		i++;
	}
	*head = NULL;
}

void 	ft_lstswap(t_c_list **head, char *stack)
{
	int	temp;

	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	ft_printf("s%s\n", stack);
}

//idea for function
// ft_for();

void	ft_c_lstiter(t_c_list *head, int (*f)(int))
{
	t_c_list *current = head;

    while (1)
	{	
    	current->content = f(current->content);
        current = current->next;
		if(current == head)
			break;
	}
}
