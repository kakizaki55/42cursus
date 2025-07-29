/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2025/07/28 13:19:08 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
