/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:10:01 by minoka            #+#    #+#             */
/*   Updated: 2025/01/15 16:29:17 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_mutexes(t_waiter *waiter)
{
	waiter->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (waiter->print_mutex == NULL)
		return (1);
	waiter->death_mutex = malloc(sizeof(pthread_mutex_t));
	if (waiter->death_mutex == NULL)
	{
		free(waiter->print_mutex);
		return (1);
	}
	if (pthread_mutex_init(waiter->print_mutex, NULL) != 0)
	{
		free(waiter->print_mutex);
		return (1);
	}
	if (pthread_mutex_init(waiter->death_mutex, NULL) != 0)
	{
		free(waiter->death_mutex);
		free(waiter->print_mutex);
		return (1);
	}
	return (0);
}

void	set_philo(t_waiter *waiter, t_philo **philos, int i)
{
	philos[i]->waiter = waiter;
	philos[i]->id = i + 1;
	philos[i]->last_ate = 0;
	philos[i]->times_ate = 0;
	philos[i]->left_fork = i;
	philos[i]->right_fork = (i + 1) % waiter->philo_count;
}

t_philo	**init_philosophers(t_waiter *waiter)
{
	t_philo			**philos;
	unsigned int	i;

	philos = calloc(waiter->philo_count, sizeof(t_philo *));
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < waiter->philo_count)
	{
		philos[i] = calloc(1, sizeof(t_philo));
		if (philos[i] == NULL)
		{
			while (--i >= 0)
				free(philos[i]);
			free(philos);
			return (NULL);
		}
		set_philo(waiter, philos, i);
		i++;
	}
	return (philos);
}

int	init(t_waiter *waiter, char *argv[])
{
	int	count;

	count = ft_atoi(argv[1]);
	waiter->philo_count = count;
	waiter->time_to_die = ft_atoi(argv[2]);
	waiter->time_to_eat = ft_atoi(argv[3]);
	waiter->time_to_sleep = ft_atoi(argv[4]);
	waiter->forks = init_forks(count);
	if (argv[5])
		waiter->times_must_eat = ft_atoi(argv[5]);
	else
		waiter->times_must_eat = -1;
	waiter->is_dead = false;
	waiter->philos = init_philosophers(waiter);
	if (waiter->philos == NULL)
		return (1);
	if (init_mutexes(waiter) != 0)
		return (1);
	return (0);
}
