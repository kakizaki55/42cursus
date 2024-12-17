/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/12/17 15:24:01 by mkakizak         ###   ########.fr       */
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
# include <stdarg.h>
# include <sys/time.h>

// typedef struct s_rules
// {
// 	unsigned int	philo_count;
// 	unsigned int	time_to_die;
// 	unsigned int	time_to_eat;
// 	unsigned int	time_to_sleep;
// }					t_rules;

typedef struct s_philo	t_philo;
// typedef struct s_waiter t_waiter;

typedef struct s_waiter
{
	unsigned int		philo_count;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	time_t				start_time;

	bool				is_dead;
    pthread_mutex_t		*print_mutex;
	t_philo				**philos;
}					t_waiter;


typedef struct s_philo
{
	pthread_t		thread;
	int				id;
    pthread_t       thread_id;
	int				last_ate;
	int			    left_fork;
	int			    right_fork;
	int				times_ate;
	t_waiter		*waiter;
}					t_philo;


//cleanup.c
void	join_threads(t_waiter *waiter);

//init.c
int 	init_mutexes(t_waiter *waiter);
t_philo **init_philosophers(t_waiter *waiter);
int 	init(t_waiter *waiter);

// utils.c
time_t	get_time_in_ms(void);
// void	print_action(int action);
// void	free_waiter(t_waiter *waiter);

//philos.c
void	*philo(void *args);

//print
void 	safe_print(t_waiter *waiter, t_philo *philom, char *str);

//libft
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif