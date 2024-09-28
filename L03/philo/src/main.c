/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:48 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/25 18:46:33 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void create_new_philo(t_rules *rules)
{
    pthread_t thread;

    pthreaf_create();

}

void run_philos(t_rules *rules)
{
    int i;
    i = 0;
    while(i < rules->philo_count)
    {
        create_new_philo(rules);
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

    char *string = "awe";
    printf("%d", SLEEPING);
}