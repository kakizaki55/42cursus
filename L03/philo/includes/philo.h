/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/25 18:45:50 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
#include <pthread.h>

typedef struct t_rules
{
    unsigned int philo_count;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
}       t_rules;



enum Action {
    EATING = 1,
    SLEEPING = 2,
    THINKING = 3
};


//utils.c

void print_action(int action);
void	*ft_calloc(size_t nmemb, size_t size);

#endif