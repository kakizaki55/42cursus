/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2024/10/14 15:16:31 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void safe_print(t_waiter *waiter, t_philo *philo, char *str)
{
    pthread_mutex_lock(waiter->print_mutex);

    printf(str, philo->id);

    pthread_mutex_unlock(waiter->print_mutex);
}

void *philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    // Philosopher logic here
    // puts("print this");
    // printf("philo is %d\n", philo->id);

    while(1)
    {
        usleep(1000 * 1000);
        // printf("philo is %d\n", philo->id);
        printf("time is: %ld milisec philos is: %d\n", (get_time_in_ms() - philo->waiter->start_time), philo->id);

    }

    // for(int i =0; i < 3; i++)
    // {
    //     usleep(1000);
    //     // printf("philo is %d\n", philo->id);
    //     printf("time is: %ld milisec philos is: %d\n", (get_time_in_ms() - philo->waiter->start_time), philo->id);
    //     // printf("time is:%ld\n", philo->waiter->start_time);
    // }
    // safe_print(philo->waiter, philo, "Philosopher is thinking\n");
    return NULL;
}