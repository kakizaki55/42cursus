/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/28 15:38:50 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void *print_somthing(void *args)
{   
    t_rules *rules = (t_rules *)args;
    // rules = (t_rules *)&rules; 
    printf("does this print%d\n", rules->philo_count);

    return (NULL);
}

// void create_new_philo(void *args)
// {
//     pthread_t thread;

// }

void run_philos(t_rules *rules)
{
    int i;
    pthread_t thread;
    i = 0;
    while(i < rules->philo_count)
    {
        pthread_create(&thread, NULL, print_somthing, (void *)rules);
        i++;
    }
}

int main(int argc, char*argv[])
{
    // need to make a file parser 
    t_rules *rules;

    rules = ft_calloc(sizeof(t_rules), 1);

    rules->philo_count = 3;
    rules->time_to_die = 600;
    rules->time_to_eat = 200;
    rules->time_to_sleep = 200;

    run_philos(rules);

    // char *string = "awe";
    // printf("%d", SLEEPING);
}