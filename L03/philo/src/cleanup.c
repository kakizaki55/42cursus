/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:14:24 by minoka            #+#    #+#             */
/*   Updated: 2025/01/13 17:45:31 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	join_threads(t_waiter *waiter)
{
	int	i;

	i = 0;
	while (i < waiter->philo_count)
	{
		pthread_join(waiter->philos[i]->thread, NULL);
		i++;
	}
}

int	free_forks(t_forks *forks)
{
	t_forks	*tmp;

	while (forks)
	{
		tmp = forks;
		pthread_mutex_destroy(tmp->fork_mutext);
		forks = forks->next;
		free(tmp->fork_mutext);
		free(tmp);
	}
	return (0);
}

void	clean_up(t_waiter *waiter)
{
	int	i;

	if (waiter == NULL)
		return ;
	free_forks(waiter->forks);
	pthread_mutex_destroy(waiter->print_mutex);
	pthread_mutex_destroy(waiter->death_mutex);
	free(waiter->print_mutex);
	free(waiter->death_mutex);
	i = 0;
	while (i < waiter->philo_count)
	{
		free(waiter->philos[i]);
		i++;
	}
	free(waiter->philos);
	free(waiter);
}
