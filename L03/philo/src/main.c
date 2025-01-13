/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2025/01/13 17:35:16 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void make_threads(t_waiter *waiter)
{
	int i;

	waiter->start_time = get_time_in_ms();
	i = 0;
	while(i < waiter->philo_count)
	{
		if (pthread_create(&waiter->philos[i]->thread, NULL, philo, waiter->philos[i]) != 0)
		{
			printf("Failed to create thread\n");
			return;
		}
		i++;
	}
}

int check_death(t_philo *philo)
{
	unsigned long long current_time;

	current_time = get_time_in_ms() - philo->waiter->start_time;
	if (philo->waiter->is_dead)
		return (1);
	if (current_time - philo->last_ate > philo->waiter->time_to_die)
	{
		pthread_mutex_lock(philo->waiter->death_mutex);
		philo->waiter->is_dead = true;
		join_threads(philo->waiter);
		safe_print(philo->waiter, philo, "%d died\n");
		pthread_mutex_unlock(philo->waiter->death_mutex);
		return (1);
	}
	return (0);
}

void check_philosophers(t_waiter *waiter)
{
	int i;
	bool all_ate;

	while (waiter->is_dead == false)
	{
		i = 0;
		all_ate = true;
		while (i < waiter->philo_count)
		{
			if (check_death(waiter->philos[i]))
			{
				pthread_mutex_lock(waiter->death_mutex);
				waiter->is_dead = true;
				pthread_mutex_unlock(waiter->death_mutex);
				clean_up(waiter);
				return;
			}
			if(waiter->philos[i]->times_ate < waiter->times_must_eat)
				all_ate = false;
			i++;
		}
		if(all_ate)
			return(clean_up(waiter));
	}
}

int main(int argc, char *argv[])
{
	t_waiter *waiter;
	int i;

	if (check_invalid_args(argc, argv) || check_arg_count(argc))
		return(EXIT_FAILURE);
	
	waiter = ft_calloc(1, sizeof(t_waiter));
	if (waiter == NULL)
	{
		printf("Failed to allocate waiter\n");
		return (1);
	}
	if (init(waiter, argc, argv) != 0)
	{
	    printf("Failed to initialize waiter\n");
		free(waiter);
		return (1);
	}
	make_threads(waiter);
	check_philosophers(waiter);
	return (EXIT_SUCCESS);
}
