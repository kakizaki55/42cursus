/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/10/09 13:38:27 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void make_philos(t_waiter *waiter)
{
    int i;
    waiter->threads = ft_calloc(sizeof(pthread_t), waiter->philo_count);
    if (waiter->threads == NULL)
    {
        // Error handling
        return;
    }
    i = 0;
    while(i < waiter->philo_count)
    {
        init_philo(i, waiter);
        if (pthread_create(&waiter->threads[i], NULL, philo, waiter) != 0)
        {
            // Error handling
            return;
        }
        i++;
    }
}

int init(t_waiter **waiter)
{
    *waiter = calloc(1, sizeof(t_waiter));
    if (*waiter == NULL)
        return 1;
    // waiter->philo_count = 3;
    // waiter->time_to_die = 600;
    // waiter->time_to_eat = 200;
    // waiter->time_to_sleep = 200;
    // waiter->print_mutex = &print_mutex;
    // waiter->is_dead = false;
    return 0;
}

int main(int argc, char *argv[])
{
    t_waiter *waiter;
    pthread_mutex_t print_mutex;

    if (init(&waiter) != 0)
    {
        // printf(stderr, "Failed to initialize waiter\n");
        return 1;
    }

    if (pthread_mutex_init(&print_mutex, NULL) != 0)
    {
        // printf(stderr, "Failed to initialize mutex\n");
        free(waiter);
        return 1;
    }

    waiter->philo_count = 3;
    waiter->time_to_die = 600;
    waiter->time_to_eat = 200;
    waiter->time_to_sleep = 200;
    waiter->print_mutex = &print_mutex;
    waiter->is_dead = false;

    make_philos(waiter);



    // waiting for thread to join

    int i = 0;
    while (i < waiter->philo_count) {
        pthread_join(waiter->threads[i], NULL);
        i++;
    }

    pthread_mutex_destroy(waiter->print_mutex);
    free(waiter->threads);
    free(waiter);

    return 0;
}