/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:54 by mkakizak          #+#    #+#             */
/*   Updated: 2024/10/06 16:37:43 by minoka           ###   ########.fr       */
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

// typedef struct s_rules
// {
// 	unsigned int	philo_count;
// 	unsigned int	time_to_die;
// 	unsigned int	time_to_eat;
// 	unsigned int	time_to_sleep;
// }					t_rules;

typedef struct s_waiter
{
	unsigned int	philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	bool			is_dead;
    pthread_t		*threads;
    pthread_mutex_t	*print_mutex;
}					t_waiter;


typedef struct s_philos
{
	int				id;
	int				last_ate;
	int				left_fork;
	int				right_fork;
	int				times_ate;
	// t_rules			*rules;
	t_waiter		*waiter;
}					t_philos;


enum				e_actions
{
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3
};

// utils.c
void				print_action(int action);

//philos.c
void	*philo(void *args);

//print
int		safe_print(t_waiter *waiter, const char *format, ...);

//libft
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif