/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/12/17 14:54:36 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

// void *print_somthing(void *args)
// {   
//     t_rules *rules = (t_rules *)args;
//     // rules = (t_rules *)&rules; 
//     printf("does this print%d\n", rules->philo_count);
//     return (NULL);
// }
void *create_new_philo(void *args)
{
    pthread_t   thread;
    t_philos    *philos;
    // t_rules     *rules;

    // rules = (t_rules*)args;
    philos = calloc(sizeof(philos), 1);
    if(philos == NULL)
        return (NULL);
    philos->rules = (t_rules *)args;

    printf("does this print?%d", philos->rules->time_to_die);
    return (NULL);

}

// void run_philos(t_rules *rules)
// {
//     int i;
//     pthread_t thread;
//     i = 0;
//     while(i < rules->philo_count)
//     {
//         pthread_create(&thread, NULL, create_new_philo, (void *)rules);
//         i++;
//     }
//     i = 0;
// }

bool init(t_rules *rules, pthread_t *philo_threads,  pthread_mutex_t **forks)
{
    int i;
    
    philo_threads = calloc(sizeof(int), rules->philo_count);
    if(philo_threads == NULL)
        return(false);
    forks = calloc (sizeof(void *), rules->philo_count);
    if(forks == NULL)
        return(false);
    i = 0;
    while(i < rules->philo_count)
    {
        pthread_mutex_init(forks[i], NULL);
        i ++;
    }
    i = 0;
    while(i < rules->philo_count)
    {
        pthread_create(&philo_threads[i], NULL, create_new_philo, (void *)rules);
        i++;
    }
    return (true);
}

bool close_threads(pthread_t    *philo_threads, t_rules *rules)
{
    int i;
    i = 0;
    while(i < rules->philo_count)
    {
        if (pthread_join(philo_threads[i], NULL) != 0)
        {
            // Handle error
            perror("pthread_join failed");
            return (false);
        }
        i++;
    }
    return (true);
}
 

int main(int argc, char*argv[])
{
    // need to make a file parser 
    t_rules *rules;
    rules = ft_calloc(sizeof(t_rules), 1);
    if(rules == NULL)
        return (EXIT_FAILURE);
    rules->philo_count = 3;
    rules->time_to_die = 600;
    rules->time_to_eat = 200;
    rules->time_to_sleep = 200;

    pthread_t       *philo_threads;
    pthread_mutex_t **forks;


    init(rules, philo_threads, forks);
    close_threads(philo_threads, rules);

    //need to make a way to init a philosopher;
    //then i can pass that one philo and make alot of threads for that philo.

    // run_philos(rules);

    // char *string = "awe";
    // printf("%d", SLEEPING);
    return(0);
}