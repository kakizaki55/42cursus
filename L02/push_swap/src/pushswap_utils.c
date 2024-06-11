/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:23:36 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/11 17:40:44 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	**ft_c_lstadd(t_c_list **head, t_c_list *new)
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
	// printf("%p\n",&(*lst)); fflush(stdout);
	res = 1;
	while (1)
	{	
		*lst = (*lst)->next;
		printf("prev%p\n",(*lst)->prev); fflush(stdout);
		printf("next%p\n",(*lst)->next); fflush(stdout);
		if(((*lst)->next) == current)
		{
			break ;
		}
		res++;
	}
	return (res);
}