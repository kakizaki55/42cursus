/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:58:06 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/21 15:37:49 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

//this function need to check if the lst is at all sorted. 

int check_sort(t_c_list *head)
{
	int i;
	t_c_list *current;

	i = 1;
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

int check_any_sort(t_c_list *head)
{
	int i;
	int target_index;

	i = 0;
	target_index = find_nbr(head, 1);

	while(i < target_index)
	{
		head = head->next;
		i++;
	}
	if(check_sort(head))
		return (target_index);
	else
		return (false);
}


