/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/12/17 15:26:36 by mkakizak         ###   ########.fr       */
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
            // fprintf(stderr, "Failed to create thread\n");
            return;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_waiter *waiter;
    int i;

    waiter = calloc(1, sizeof(t_waiter));
    if (waiter == NULL)
    {
        // NEED TO DO ERROR HANDELING
        // printf(stderr, "Failed to allocate waiter\n");
        return 1;
    }

    if (init(waiter) != 0)
    {
        //NEED TO DO ERROR HANDLING
        // printf(stderr, "Failed to initialize waiter\n");
        free(waiter);
        return 1;
    }

    make_threads(waiter);

    join_threads(waiter);

    // Cleanup this can go into another file
    pthread_mutex_destroy(waiter->print_mutex);
    free(waiter->print_mutex);
    for (i = 0; i < waiter->philo_count; i++) {
        free(waiter->philos[i]);
    }
    free(waiter->philos);
    free(waiter);

    return (EXIT_SUCCESS);
}