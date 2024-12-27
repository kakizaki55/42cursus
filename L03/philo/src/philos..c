/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2024/12/27 22:34:09 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void safe_print(t_waiter *waiter, t_philo *philo, char *str)
{
    pthread_mutex_lock(waiter->print_mutex);
	printf("%ld ", get_time_in_ms() - waiter->start_time);
    printf(str, philo->id);
    pthread_mutex_unlock(waiter->print_mutex);
}

void *philo(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	// Philosopher logic here
	unsigned long long start_time;
	t_forks *left_fork;
	t_forks *right_fork;

	start_time = philo->waiter->start_time;

	if (philo->id % 2 == 0)
		usleep(1000);

	while(1)
	{
		safe_print(philo->waiter, philo, "%d is sleeping\n");
		usleep(philo->waiter->time_to_sleep * 1000 * 1);

		// usleep(1000 * 1000);
		// printf("philo is %d\n", philo->id);
		// if philo has access to both forks then eat;
		// if philo has access to only one fork then wait;
		left_fork = get_fork_by_index(philo->waiter->forks, philo->left_fork);
		right_fork = get_fork_by_index(philo->waiter->forks, philo->right_fork);

		safe_print(philo->waiter, philo, "%d is thinking\n");
		// Try to take forks
		// printf("philo left %d\n", philo->left_fork);
		pthread_mutex_lock(left_fork->fork_mutext);
		safe_print(philo->waiter, philo, "%d has taken left fork\n");

		// printf("philo right %d\n", philo->right_fork);
		pthread_mutex_lock(right_fork->fork_mutext);
		safe_print(philo->waiter, philo, "%d has taken right fork\n");

		// if(check_death(philo) != 0)
		// 	return (NULL);
		// Eating state

		safe_print(philo->waiter, philo, "%d is eating\n");
		philo->last_ate = get_time_in_ms() - start_time;
		usleep(philo->waiter->time_to_eat * 1000 * 1);

		// Release forks
		pthread_mutex_unlock(left_fork->fork_mutext);
		pthread_mutex_unlock(right_fork->fork_mutext);

		// Sleeping state

		// Thinking state
	}

	return (NULL);
}