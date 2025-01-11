/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2025/01/11 16:24:56 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>

// pid_t tid = gettid();


void safe_print(t_waiter *waiter, t_philo *philo, char *str)
{
    pthread_mutex_lock(waiter->print_mutex);
	// printf("p_id: %d ", philo->process_id);
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

	// this is for debugging
	pid_t process_id = gettid();
	philo->process_id = process_id;

	while(philo->waiter->is_dead == false)
	{	
		// pthread_mutex_lock(philo->waiter->death_mutex);
		// if(philo->waiter->is_dead == true)
		// 	break ;
		// pthread_mutex_unlock(philo->waiter->death_mutex);

		safe_print(philo->waiter, philo, "%d is sleeping\n");
		usleep(philo->waiter->time_to_sleep * 1000 * 1);

		safe_print(philo->waiter, philo, "%d is thinking\n");
		left_fork = get_fork_by_index(philo->waiter->forks, philo->left_fork);
		right_fork = get_fork_by_index(philo->waiter->forks, philo->right_fork);

		// Try to take forks

		pthread_mutex_lock(left_fork->fork_mutext);
		safe_print(philo->waiter, philo, "%d has taken a fork\n");
		// printf("philo right %d\n", philo->right_fork);
		pthread_mutex_lock(right_fork->fork_mutext); 
		safe_print(philo->waiter, philo, "%d has taken a fork\n");

		// if(check_death(philo) != 0)
		// 	return (NULL);
		// Eating state

		safe_print(philo->waiter, philo, "%d is eating\n");
		philo->last_ate = get_time_in_ms() - start_time;
		usleep(philo->waiter->time_to_eat * 1000 * 1);

		// Release forks
		pthread_mutex_unlock(left_fork->fork_mutext);
		pthread_mutex_unlock(right_fork->fork_mutext);

		// Thinking state
	}

	return (NULL);
}