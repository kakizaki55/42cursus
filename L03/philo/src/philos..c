/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2025/01/15 18:54:39 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	handle_sleep_think(t_philo *philo)
{
	if (get_death(philo->waiter) == false)
	{
		safe_print(philo->waiter, philo, "%d is sleeping\n");
		usleep(philo->waiter->time_to_sleep * 1000 * 1);
	}
	if (get_death(philo->waiter) == false)
		safe_print(philo->waiter, philo, "%d is thinking\n");
}

bool	acquire_forks(t_philo *philo, t_forks **left_fork, t_forks **right_fork)
{
	*left_fork = get_fork_by_index(philo->waiter->forks, philo->left_fork);
	*right_fork = get_fork_by_index(philo->waiter->forks, philo->right_fork);

	if(philo->waiter->philo_count == 1)
	{
		pthread_mutex_lock((*left_fork)->fork_mutext);
		safe_print(philo->waiter, philo, "%d has taken a fork\n");
		pthread_mutex_unlock((*left_fork)->fork_mutext);
		return (false);
	}

	if (philo->id % 2 == 0) 
	{
		pthread_mutex_lock((*left_fork)->fork_mutext);
		if (get_death(philo->waiter))
		{
			pthread_mutex_unlock((*left_fork)->fork_mutext);
			return (false);
		}
		safe_print(philo->waiter, philo, "%d has taken a fork\n");

		pthread_mutex_lock((*right_fork)->fork_mutext);
		if (get_death(philo->waiter))
		{
			pthread_mutex_unlock((*left_fork)->fork_mutext);
			pthread_mutex_unlock((*right_fork)->fork_mutext);
			return (false);
		}
	} else {
		pthread_mutex_lock((*right_fork)->fork_mutext);
		if (get_death(philo->waiter)) 
		{
			pthread_mutex_unlock((*right_fork)->fork_mutext);
			return (false);
		}
		safe_print(philo->waiter, philo, "%d has taken a fork\n");
	
		pthread_mutex_lock((*left_fork)->fork_mutext);
		if (get_death(philo->waiter))
		{
			pthread_mutex_unlock((*right_fork)->fork_mutext);
			pthread_mutex_unlock((*left_fork)->fork_mutext);
			return (false);
		}
	}

	safe_print(philo->waiter, philo, "%d has taken a fork\n");
	return (true);
}

void	handle_eating(t_philo *philo, unsigned long long start_time,
		t_forks *left_fork, t_forks *right_fork)
{
	// pthread_mutex_lock(philo->waiter->death_mutex);
	philo->last_ate = get_time_in_ms() - start_time;
	philo->times_ate++;
	// pthread_mutex_unlock(philo->waiter->death_mutex);

	safe_print(philo->waiter, philo, "%d is eating\n");
	philo->last_ate = get_time_in_ms() - start_time;
	usleep(philo->waiter->time_to_eat * 1000 * 1);
	pthread_mutex_unlock(left_fork->fork_mutext);
	pthread_mutex_unlock(right_fork->fork_mutext);
}

void	*philo(void *arg)
{
	t_philo				*philo;
	unsigned long long	start_time;
	t_forks				*left_fork;
	t_forks				*right_fork;

	philo = (t_philo *)arg;
	start_time = philo->waiter->start_time;
	if (philo->id % 2 == 0)
		usleep(1000);
	
	while (philo->waiter->is_dead == false)
	{
		handle_sleep_think(philo);
		if (get_death(philo->waiter))
			break ;
		if (!acquire_forks(philo, &left_fork, &right_fork))
			break ;
		if (get_death(philo->waiter))
			break ;
		handle_eating(philo, start_time, left_fork, right_fork);
	}
	return (NULL);
}
