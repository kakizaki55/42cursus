/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2025/01/11 16:46:02 by mkakizak         ###   ########.fr       */
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
typedef struct s_forks	t_forks;
// typedef struct s_waiter t_waiter;

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
}					t_waiter;

typedef struct s_forks
{
	int 			fork;
	pthread_mutex_t *fork_mutext;
	t_forks 		*next;
}					t_forks;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_t		thread_id;
	int				last_ate;
	int				left_fork;
	int				right_fork;
	int				times_ate;
	t_waiter		*waiter;
	pid_t			process_id;
}					t_philo;


//cleanup.c
void		detach_threads(t_waiter *waiter);

//init.c
int 		init_mutexes(t_waiter *waiter);
t_philo		**init_philosophers(t_waiter *waiter);
int 		init(t_waiter *waiter, int argc, char *argv[]);

// utils.c
time_t		get_time_in_ms(void);
int			free_forks(t_forks *forks);
// void		print_action(int action);
// void		free_waiter(t_waiter *waiter);
t_forks 	*get_fork_by_index(t_forks *head, int index);


//philos.c
void		*philo(void *args);
int			check_death(t_philo *philo);

//print
void 		safe_print(t_waiter *waiter, t_philo *philom, char *str);

//libft
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);

#endif