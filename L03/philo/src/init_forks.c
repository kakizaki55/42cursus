/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:39:23 by mkakizak          #+#    #+#             */
/*   Updated: 2025/01/13 17:54:25 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static t_forks	*create_fork_node(int fork_number)
{
	t_forks	*node;

	node = ft_calloc(sizeof(t_forks), 1);
	if (node == NULL)
		return (NULL);
	node->fork = fork_number;
	node->fork_mutext = ft_calloc(sizeof(pthread_mutex_t), 1);
	if (node->fork_mutext == NULL)
	{
		free(node);
		return (NULL);
	}
	if (pthread_mutex_init(node->fork_mutext, NULL) != 0)
	{
		free(node->fork_mutext);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

static t_forks	*link_fork_node(t_forks *current, int fork_number)
{
	t_forks	*new_node;

	new_node = create_fork_node(fork_number);
	if (new_node == NULL)
		return (NULL);
	current->next = new_node;
	return (new_node);
}

t_forks	*init_forks(int philo_count)
{
	t_forks	*head;	
	t_forks	*current;
	int		i;

	head = create_fork_node(0);
	if (head == NULL)
	{
		printf("Failed to allocate forks\n");
		return (NULL);
	}
	current = head;
	i = 1;
	while (i < philo_count)
	{
		current = link_fork_node(current, i);
		if (current == NULL)
		{
			free_forks(head);
			return (NULL);
		}
		i++;
	}
	return (head);
}
