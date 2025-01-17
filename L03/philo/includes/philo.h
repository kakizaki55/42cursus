/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2025/01/17 16:21:32 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_forks	t_forks;

typedef struct s_waiter
{
	unsigned int		philo_count;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	time_t				start_time;
	t_forks				*forks;
	bool				is_dead;
	unsigned int		times_must_eat;
	pthread_mutex_t		*death_mutex;
	pthread_mutex_t		*print_mutex;
	t_philo				**philos;
}						t_waiter;

typedef struct s_forks
{
	int					fork;
	pthread_mutex_t		*fork_mutext;
	t_forks				*next;
}						t_forks;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					last_ate;
	int					left_fork;
	int					right_fork;
	int					times_ate;
	t_waiter			*waiter;
}						t_philo;

// libft
int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
int						ft_isdigit(int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

// utils.c / time.c
time_t					get_time_in_ms(void);
t_forks					*get_fork_by_index(t_forks *head, int index);
void					safe_print(t_waiter *waiter, t_philo *philom,
							char *str);
bool					get_death(t_waiter *waiter);

// cleanup.c
void					join_threads(t_waiter *waiter);
int						free_forks(t_forks *forks);
void					clean_up(t_waiter *waiter);

// error.c
bool					check_arg_count(int argc);
bool					check_invalid_args(int argc, char *argv[]);

// init.c
int						init_mutexes(t_waiter *waiter);
t_philo					**init_philosophers(t_waiter *waiter);
int						init(t_waiter *waiter, char *argv[]);

// init_forks.c
t_forks					*init_forks(int philo_count);

// philos.c
void					*philo(void *args);

// philos_utils.c
void					handle_sleep_think(t_philo *philo);
bool					get_left_fork_first(t_philo *philo, t_forks **left_fork,
							t_forks **right_fork);
bool					get_right_fork_first(t_philo *philo,
							t_forks **left_fork, t_forks **right_fork);
bool					acquire_forks(t_philo *philo, t_forks **left_fork,
							t_forks **right_fork);
void					handle_eating(t_philo *philo,
							unsigned long long start_time, t_forks *left_fork,
							t_forks *right_fork);

#endif