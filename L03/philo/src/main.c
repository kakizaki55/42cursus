/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/10/06 15:14:57 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void make_philos(t_rules *rules, t_waiter *waiter)
{
    int i;
    pthread_t threads;


    waiter->threads = ft_calloc(sizeof(pthread_t), rules->philo_count);
    if(waiter->threads == NULL)
    {
        //ERROR HANDLING
        return ;
    }

    i = 0;
    while(i < rules->philo_count)
    {
        pthread_create(&threads, NULL, philo, (void *)rules);
        waiter->threads[i] = threads;
        printf("threads:%lu",waiter->threads[i]);
        i++;
    }
}

int init(t_rules **rules, t_waiter **waiter)
{
    //probally should exit instead of return later
    *rules = ft_calloc(sizeof(t_rules), 1);
    if(rules == NULL)
        return (1);

    *waiter =  ft_calloc(sizeof(t_waiter), 1);
    if(waiter == NULL)
        return(1);

    return (0);
}

int main(int argc, char*argv[])
{
    // need to make a file parser
    t_rules     *rules;
    t_waiter    *waiter;

    init(&rules, &waiter);

    rules->philo_count = 3;
    rules->time_to_die = 600;
    rules->time_to_eat = 200;
    rules->time_to_sleep = 200;

    waiter->threads = ft_calloc(sizeof(int), rules->philo_count);
    if(waiter->threads == NULL)
        return (1);

     make_philos(rules, waiter);

    return (0);
}