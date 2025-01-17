/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:10:57 by minoka            #+#    #+#             */
/*   Updated: 2025/01/17 16:12:06 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_forks	*get_fork_by_index(t_forks *head, int index)
{
	t_forks	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}

void	safe_print(t_waiter *waiter, t_philo *philo, char *str)
{
	pthread_mutex_lock(waiter->print_mutex);
	printf("%ld ", get_time_in_ms() - waiter->start_time);
	printf(str, philo->id);
	pthread_mutex_unlock(waiter->print_mutex);
}

bool get_death(t_waiter *waiter)
{
	bool res;

	pthread_mutex_lock(waiter->death_mutex);
	res = waiter->is_dead;
	pthread_mutex_unlock(waiter->death_mutex);
	return (res);
}


