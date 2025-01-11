/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:14:24 by minoka            #+#    #+#             */
/*   Updated: 2025/01/11 16:46:52 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	detach_threads(t_waiter *waiter)
{
	int i;
	i = 0;
	while(i < waiter->philo_count)
	{
		pthread_detach(waiter->philos[i]->thread);
		i++;
	}
}

int	free_forks(t_forks *forks)
{
	t_forks *tmp;

	while (forks)
	{
		tmp = forks;
		forks = forks->next;
		pthread_mutex_destroy(tmp->fork_mutext);
		free(tmp->fork_mutext);
		free(tmp);
	}
	return (0);
}