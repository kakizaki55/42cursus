/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:23:36 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/12 23:50:49 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

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

int	ft_c_lstsize(t_c_list **lst)
{
	int	res;
	t_c_list *current;

	current = *lst;
	res = 1;
	while (1)
	{	
		*lst = (*lst)->next;
		if(*lst == current)
		{
			return (res);
		}
		res++;
	}
	return (res);
}

void print_lst(t_c_list *head)
{
	t_c_list *current = head;
	int i;

	i = 0;
    while (1)
	{	
        ft_printf("[%d]:%d\n", i, current->content);
        current = current->next;
		i++;
		if(current == head)
			break;
	}
}

void rotate(t_c_list **head)
{
	*head = (*head)->next;
}

void r_rotate(t_c_list **head)
{
	*head = (*head)->prev;
}

t_c_list *ft_lstpop(t_c_list **head)
{
	t_c_list *poped; 
	t_c_list *temp;

	temp = *head;
	poped = ft_c_lstnew((*head)->content);
	(*head)->prev->next = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	*head = (*head)->next;
	free(temp);
	poped->next = poped;
	poped->prev = poped;
	return (poped);
}

void 	ft_lstswap(t_c_list **head)
{
	int	temp;

	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
}

//idea for function
// ft_for();


// there are more addiatianl functions
int add2(int number)
{
	return (number + 2);
}
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