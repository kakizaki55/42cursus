/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2025/01/13 17:34:54 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void handle_sleep_think(t_philo *philo)
{
	safe_print(philo->waiter, philo, "%d is sleeping\n");
	usleep(philo->waiter->time_to_sleep * 1000 * 1);

	if(!philo->waiter->is_dead)
		safe_print(philo->waiter, philo, "%d is thinking\n");
}

bool acquire_forks(t_philo *philo, t_forks **left_fork, t_forks **right_fork)
{
	*left_fork = get_fork_by_index(philo->waiter->forks, philo->left_fork);
	*right_fork = get_fork_by_index(philo->waiter->forks, philo->right_fork);

	if (philo->waiter->is_dead)
		return false;
	
	pthread_mutex_lock((*left_fork)->fork_mutext);
	safe_print(philo->waiter, philo, "%d has taken a fork\n");

	if(philo->waiter->is_dead)
		return false;

	pthread_mutex_lock((*right_fork)->fork_mutext);
	safe_print(philo->waiter, philo, "%d has taken a fork\n");
	return true;
}

void handle_eating(t_philo *philo, unsigned long long start_time, 
			t_forks *left_fork, t_forks *right_fork)
{
	safe_print(philo->waiter, philo, "%d is eating\n");
	philo->last_ate = get_time_in_ms() - start_time;
	philo->times_ate++;
	usleep(philo->waiter->time_to_eat * 1000 * 1);
	pthread_mutex_unlock(left_fork->fork_mutext);
	pthread_mutex_unlock(right_fork->fork_mutext);
}

void *philo(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	unsigned long long start_time = philo->waiter->start_time;
	t_forks *left_fork;
	t_forks *right_fork;

	if (philo->id % 2 == 0)
		usleep(1000);

	while(philo->waiter->is_dead == false)
	{
		handle_sleep_think(philo);
	
		if(philo->waiter->is_dead)
			break;
	
		if (!acquire_forks(philo, &left_fork, &right_fork))
			break;
	
		if (philo->waiter->is_dead)
		break;
	
		handle_eating(philo, start_time, left_fork, right_fork);
	}
	return (NULL);
}
