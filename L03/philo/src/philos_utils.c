/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:13:14 by minoka            #+#    #+#             */
/*   Updated: 2025/01/17 16:21:08 by minoka           ###   ########.fr       */
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

bool	get_left_fork_first(t_philo *philo, t_forks **left_fork,
		t_forks **right_fork)
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
	return (true);
}

bool	get_right_fork_first(t_philo *philo, t_forks **left_fork,
		t_forks **right_fork)
{
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
	return (true);
}

bool	acquire_forks(t_philo *philo, t_forks **left_fork, t_forks **right_fork)
{
	*left_fork = get_fork_by_index(philo->waiter->forks, philo->left_fork);
	*right_fork = get_fork_by_index(philo->waiter->forks, philo->right_fork);
	if (philo->waiter->philo_count == 1)
	{
		pthread_mutex_lock((*left_fork)->fork_mutext);
		safe_print(philo->waiter, philo, "%d has taken a fork\n");
		pthread_mutex_unlock((*left_fork)->fork_mutext);
		return (false);
	}
	if (philo->id % 2 == 0)
	{
		if (get_left_fork_first(philo, left_fork, right_fork) == false)
			return (false);
	}
	else
	{
		if (get_right_fork_first(philo, left_fork, right_fork) == false)
			return (false);
	}
	safe_print(philo->waiter, philo, "%d has taken a fork\n");
	return (true);
}

void	handle_eating(t_philo *philo, unsigned long long start_time,
		t_forks *left_fork, t_forks *right_fork)
{
	philo->last_ate = get_time_in_ms() - start_time;
	safe_print(philo->waiter, philo, "%d is eating\n");
	philo->last_ate = get_time_in_ms() - start_time;
	usleep(philo->waiter->time_to_eat * 1000 * 1);
	philo->times_ate++;
	pthread_mutex_unlock(left_fork->fork_mutext);
	pthread_mutex_unlock(right_fork->fork_mutext);
}
