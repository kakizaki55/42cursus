/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2025/01/17 16:21:04 by minoka           ###   ########.fr       */
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
