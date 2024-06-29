/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:58:06 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/29 21:51:43 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

int check_sort(t_c_list *head)
{
	int i;
	t_c_list *current;

	i = find_min(head);
	current = head;

    while (1)
	{	
    	if(current->content == i)
		{
        	current = current->next;
			i++;
		}
		else
		{
			return (false);
		}
		if(current == head)
			return (true);
	}
	return (false);
}

int check_r_sort(t_c_list *head)
{
	int i;
	t_c_list *current;

	i = ft_c_lstsize(head);
	current = head;


    while (1)
	{	
    	if(current->content == i)
		{
			i--;
        	current = current->next;
		}
		else
		{
			return (false);
		}
		if(current == head)
			return (true);
	}
	return (false);
}

int find_nbr(t_c_list *head, int nbr)
{
	if(head == NULL || nbr == 0)
		return (false);
	int i;
	t_c_list *current;

	i = 0;
	current = head;

    while (1)
	{	
    	if(current->content != nbr)
		{
			i++;
        	current = current->next;
		} 
		else
		{
			return (i);
		}
		if(current == head)
			return(false);
	}
	return (false);
}

int find_r_nbr(t_c_list *head, int nbr)
{
	if(head == NULL || nbr == 0)
		return (false);
	int i;
	t_c_list *current;

	i = 0;
	current = head;

    while (1)
	{	
    	if(current->content != nbr)
		{
			i++;
        	current = current->prev;
		} 
		else
		{
			return (i);
		}
		if(current == head)
			return(false);
	}
	return (false);
}

int check_any_sort(t_c_list *head)
{
	int size;
	int i;

	i = 0;
	size = ft_c_lstsize(head);
	while(i < size)
	{
		if(check_sort(head))
			return (true);
		head = head->next;
		i++;
	}
	if(check_sort(head))
		return (true);
	else
		return (false);
}

int check_any_r_sort(t_c_list *head)
{
	int size;
	int i;

	i = 0;
	size = ft_c_lstsize(head);
	while(i < size)
	{
		if(check_r_sort(head))
			return (true);
		head = head->prev;
		i++;
	}
	if(check_r_sort(head))
		return (true);
	else
		return (false);
}

int find_min(t_c_list *head)
{
	t_c_list *current = head;
	int res;

	res = INT_MAX;
	while (1)
	{	if(res > current->content && (current->content > 0))
			res = current->content;
        current = current->next;
		if(current == head)
		{
			return (res);
		}
	}
	return (0);
}

int find_max(t_c_list *head)
{
	t_c_list *current = head;
	int res;

	res = INT_MIN;
	while (1)
	{	if(res < current->content)
			res = current->content;
        current = current->next;
		if(current == head)
		{
			return (res);
		}
	}
	return (0);
}

int recon_smaller(t_c_list *head, int deli)
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
		if(temp->content <= deli)
			return (index);
		temp = temp->next;
		index++;
		if(r_temp->content <= deli)
			return (r_index);
		r_temp = r_temp->prev;
		r_index--;
		i++;
	}
	return (INT_MAX);
}

int recon_larger(t_c_list *head, int deli)
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
		if(temp->content > deli)
			return (index);
		temp = temp->next;
		index++;
		if(r_temp->content > deli)
			return (r_index);
		r_temp = r_temp->prev;
		r_index--;
		i++;
	}
	return (0);
}

void push_all(t_c_list **src_lst, t_c_list **dest_lst, char dest_stack)
{
	int i = 0;

	int size = ft_c_lstsize(*src_lst);
	while (i < size)
	{
		ft_c_push(src_lst, dest_lst, dest_stack);
		i++;
	}
	*src_lst = NULL;
}

void push_all_large(t_c_list **src_lst, t_c_list **dest_lst, char dest_stack)
{
	int i = 0;
	int biggest;
	
	// biggest =  find_max(*src_lst);
	int size = ft_c_lstsize(*src_lst);
	if((*src_lst)->content == biggest)
	{
		while (i < size)
		{
			ft_c_push(src_lst, dest_lst, dest_stack);
			i++;
		}
	}
	*src_lst = NULL;
}
