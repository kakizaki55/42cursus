/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/28 15:05:22 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_rules
{
	unsigned int	philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
}					t_rules;

typedef struct s_philos
{
	int				id;
	int				last_ate;
	int				left_fork;
	int				right_fork;
	int				times_ate;
	struct t_rules	*rules;
}					t_philos;

typedef struct s_waiter
{
	bool			    is_dead;
    pthread_mutex_t     *forks;
    pthread_mutex_t     *printing_action;
}					t_waiter;

enum				e_actions
{
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3
};

// utils.c

void				print_action(int action);
void				*ft_calloc(size_t nmemb, size_t size);


//ft_atoi.c
int	                ft_atoi(const char *str);

#endif