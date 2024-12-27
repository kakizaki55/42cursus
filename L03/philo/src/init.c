/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:10:01 by minoka            #+#    #+#             */
/*   Updated: 2024/12/27 22:44:33 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int init_mutexes(t_waiter *waiter)
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

	return(0);
}

t_philo **init_philosophers(t_waiter *waiter)
{
    t_philo **philos;
    int i;

    philos = calloc(waiter->philo_count, sizeof(t_philo *));
    if(philos == NULL)
        return NULL;

    for(i = 0; i < waiter->philo_count; i++)
    {
        philos[i] = calloc(1, sizeof(t_philo));
        if(philos[i] == NULL)
        {
            // Free previously allocated memory
            while (--i >= 0)
                free(philos[i]);
            free(philos);
            return NULL;
        }
        philos[i]->waiter = waiter;
        philos[i]->id = i + 1;
        philos[i]->last_ate = 0;
        philos[i]->times_ate = 0;
        philos[i]->left_fork = i;
        philos[i]->right_fork = (i + 1) % waiter->philo_count;
    }
    return philos;
}

t_forks *init_forks(int philo_count)
{
    t_forks *head;
    t_forks *current;
	t_forks *new_node;
    int i;

    head = ft_calloc(sizeof(t_forks), 1);
    if(head == NULL)
    {
        // error handling done here;
        return(NULL);
    }
    current = head;
	i = 0;
	while(i <= philo_count)
	{
		current->fork = i;
		current->fork_mutext = ft_calloc(sizeof(pthread_mutex_t), 1);
		if(current->fork_mutext == NULL)
		{
			// error handling done here;
			free(head);
			return(NULL);
		}
		if (pthread_mutex_init(current->fork_mutext, NULL) != 0)
			free(current);

		if(i < philo_count - 1)
		{
			new_node = ft_calloc(sizeof(t_forks), 1);
			if(new_node == NULL)
			{
				// error handling done here;
				free(head);
				return(NULL);
			}
			current->next = new_node;
			current = current->next;
		}
		i++;
	}
	return(head);
}

int init(t_waiter *waiter, int argc, char *argv[])
{
	int count;

	count  = ft_atoi(argv[1]);
	waiter->philo_count = count;
	waiter->time_to_die = ft_atoi(argv[2]);
	waiter->time_to_eat = ft_atoi(argv[3]);
	waiter->time_to_sleep = ft_atoi(argv[4]);
	waiter->forks = init_forks(count);
	if(argv[5])
		waiter->times_must_eat = ft_atoi(argv[5]);
	else
		waiter->times_must_eat = -1;
	waiter->is_dead = false;
	waiter->philos = init_philosophers(waiter);
	if (waiter->philos == NULL)
		return (1);
	if (init_mutexes(waiter) != 0)
		return (1);

	return(0);
}