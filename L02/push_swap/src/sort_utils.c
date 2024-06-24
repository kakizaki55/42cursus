/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:58:06 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/24 20:54:30 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

//this function need to check if the lst is at all sorted. 

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
	{	if(res > current->content)
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


