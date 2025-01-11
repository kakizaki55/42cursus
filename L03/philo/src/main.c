/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2025/01/11 17:25:58 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void make_threads(t_waiter *waiter)
{
	int i;

	waiter->start_time = get_time_in_ms();
	printf("start time: %lu\n", waiter->start_time);

	i = 0;
	while(i < waiter->philo_count)
	{
		if (pthread_create(&waiter->philos[i]->thread, NULL, philo, waiter->philos[i]) != 0)
		{
			write(STDERR_FILENO, "Failed to create thread\n", 23);
			return;
		}
		i++;
	}
}

void clean_up(t_waiter *waiter)
{	
	int i;
	if(waiter == NULL)
		return;

	free_forks(waiter->forks);
	pthread_mutex_destroy(waiter->print_mutex);
	free(waiter->print_mutex);
	i = 0;
	while(i < waiter->philo_count)
	{
		free(waiter->philos[i]);
		i++;
	}
	free(waiter->philos);
	free(waiter);
}

int check_death(t_philo *philo)

{
	unsigned long long current_time;

	current_time = get_time_in_ms() - philo->waiter->start_time;

	// printf("is dead: %d\n", philo->waiter->is_dead);
	if (philo->waiter->is_dead)
		return (1);
	// safe_print(philo->waiter, philo, "%d is checking for death\n");
	// printf("current time: %lld last ate: %d time_ to die:%ld\n", current_time, philo->last_ate, philo->waiter->time_to_die);
	if (current_time - philo->last_ate > philo->waiter->time_to_die)
	{
		pthread_mutex_lock(philo->waiter->death_mutex);
		philo->waiter->is_dead = true;
		// usleep(1000);
		safe_print(philo->waiter, philo, "%d died\n");
		pthread_mutex_unlock(philo->waiter->death_mutex);
		// detach_threads(philo->waiter);
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
		{
			clean_up(waiter);
			return;
		}
		// usleep(1000); // Small delay to prevent CPU overload
	}
}

bool check_invalid_args(int argc, char *argv[])
{
	int i;
	int j;
	
	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				return (true);
			}
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

int main(int argc, char *argv[])
{
    t_waiter *waiter;
    int i;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments:");
		// printf("number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}

	if (check_invalid_args(argc, argv))
	{
		printf("Invalid arguments: All argmunets must be positive numbers\n");
		return(EXIT_FAILURE);
	}
	

	waiter = ft_calloc(1, sizeof(t_waiter));
	if (waiter == NULL)
	{
		printf("Failed to allocate waiter\n");
		return (1);
	}

	if (init(waiter, argc, argv) != 0)
	{
	    //NEED TO DO ERROR HANDLING
	    // printf(stderr, "Failed to initialize waiter\n");
		free(waiter);
		return (1);
	}
	make_threads(waiter);
	check_philosophers(waiter);
	// clean_up(waiter);
	return (EXIT_SUCCESS);
}