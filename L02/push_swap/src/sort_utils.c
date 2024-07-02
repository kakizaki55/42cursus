/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:58:06 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/02 18:50:13 by mkakizak         ###   ########.fr       */
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

int	check_any_r_sort(t_c_list *head)
{
	int	size;
	int	i;

	i = 0;
	size = ft_c_lstsize(head);
	while (i < size)
	{
		if (check_r_sort(head))
			return (TRUE);
		head = head->prev;
		i++;
	}
	if (check_r_sort(head))
		return (TRUE);
	else
		return (FALSE);
}

int	find_min(t_c_list *head)
{
	t_c_list	*current;
	int			res;

	current = head;
	res = INT_MAX;
	while (1)
	{	
		if (res > current->content && (current->content > 0))
			res = current->content;
		current = current->next;
		if (current == head)
		{
			return (res);
		}
	}
	return (0);
}

int find_max(t_c_list *head)
{
	t_c_list	*current;
	int			res;

	current = head;
	res = INT_MIN;
	while (1)
	{	
		if (res < current->content)
			res = current->content;
		current = current->next;
		if (current == head)
		{
			return (res);
		}
	}
	return (0);
}

int recon_smaller(t_c_list *head, int deli)
{
	int			i;
	int			index;
	int			r_index;
	t_c_list	*temp;
	t_c_list	*r_temp;
	int			lst_size;

	lst_size = ft_c_lstsize(head);
	i = 0;
	index = 0;
	r_index = 0;
	temp = head;
	r_temp = head;
	while (i < lst_size)
	{
		if (temp->content <= deli)
			return (index);
		temp = temp->next;
		index++;
		if (r_temp->content <= deli)
			return (r_index);
		r_temp = r_temp->prev;
		r_index--;
		i++;
	}
	return (INT_MAX);
}

int recon_larger(t_c_list *head, int deli)
{
	int			i;
	int			index;
	int			r_index;
	t_c_list	*temp;
	t_c_list	*r_temp;
	int lst_size;

	lst_size = ft_c_lstsize(head);
	i = 0;
	index = 0;
	r_index = 0;
	temp = head;
	r_temp = head;
	while (i < lst_size)
	{
		if (temp->content > deli)
			return (index);
		temp = temp->next;
		index++;
		if (r_temp->content > deli)
			return (r_index);
		r_temp = r_temp->prev;
		r_index--;
		i++;
	}
	return (0);
}

void	push_all(t_c_list **src_lst, t_c_list **dest_lst, char dest_stack)
{
	int	i;
	int	size;

	size = ft_c_lstsize(*src_lst);
	i = 0;
	while (i < size)
	{
		ft_c_push(src_lst, dest_lst, dest_stack);
		i++;
	}
	*src_lst = NULL;
}

void push_all_large(t_c_list **src, t_c_list **dest, char dest_stack)
{
	int i;
	int biggest;
	int size;

	i = 0;
	size = ft_c_lstsize(*src);
	if ((*src)->content == biggest)
	{
		while (i < size)
		{
			ft_c_push(src, dest, dest_stack);
			i++;
		}
	}
	*src = NULL;
}

int	find_sortest_path(t_c_list **src, int target_nbr)
{	
	int	res;

	res = 0;
	if (is_smaller(find_nbr(*src, target_nbr), find_r_nbr(*src, target_nbr)))
		res = find_nbr(*src, target_nbr);
	else
		res = find_r_nbr(*src, target_nbr) * -1;
	return (res);
}
void	split_lsts_tw_thr(t_c_list **stack_a, t_c_list **stack_b, int len)
{
	int	i;
	int	index;
	int	half;

	i = 0;
	index = 0;
	half = ft_c_lstsize(*stack_a) / 2;
	while (i++ < half)
	{
		index = recon_smaller(*stack_a, half);
		while (index != 0)
		{
			if (index > 0)
			{
				ft_rotate(stack_a, 'a');
				index--;
			}
			else
			{
				ft_r_rotate(stack_a, 'a');
				index++;
			}
		}
		ft_c_push(stack_a, stack_b, 'b');
	}
	// ft_c_print_lst(*stack_a, 'a');
	// ft_c_print_lst(*stack_b, 'b');
}

char	get_other_stack(char c)
{	
	if (c == 'a')
		return ('b');
	else
		return ('a');
	return (' ');
}

void		splt_lst_hlf(t_c_list **src, t_c_list **dest, char stk, int dlmt)
{
	int		i;
	int		index;
	int		len;
	char	src_stack;

	i = 0;
	index = 0;
	len = (ft_c_lstsize(*src) / 2);
	src_stack = get_other_stack(stk);
	while (i++ <= len)
	{
		if (stk == 'b')
		{
			index = recon_smaller(*src, dlmt);
			if (index == INT_MAX)
			{
				i++;
				break ;
			}
		}
		else
			index = recon_larger(*src, dlmt);
		rotate_stack(src, src_stack, index);
		ft_c_push(src, dest, stk);
	}
}
