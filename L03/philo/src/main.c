/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/10/06 16:41:35 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void make_philos(t_waiter *waiter) {
    int i;

    waiter->threads = calloc(waiter->philo_count, sizeof(pthread_t));
    if (waiter->threads == NULL) {
        // Error handling
        return;
    }
    i = 0;
    while(i < waiter->philo_count) {
        if (pthread_create(&waiter->threads[i], NULL, philo, waiter) != 0) {
            // Error handling
            return;
        }
        i++;
    }
}

int init(t_waiter **waiter) {
    *waiter = calloc(1, sizeof(t_waiter));
    if (*waiter == NULL)
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    t_waiter *waiter;
    pthread_mutex_t print_mutex;

    if (init(&waiter) != 0) {
        fprintf(stderr, "Failed to initialize waiter\n");
        return 1;
    }

    if (pthread_mutex_init(&print_mutex, NULL) != 0) {
        fprintf(stderr, "Failed to initialize mutex\n");
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

    // Wait for threads to finish
    for (int i = 0; i < waiter->philo_count; i++) {
        pthread_join(waiter->threads[i], NULL);
    }

    pthread_mutex_destroy(&print_mutex);
    free(waiter->threads);
    free(waiter);

    return 0;
}