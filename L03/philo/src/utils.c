/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:22:53 by mkakizak          #+#    #+#             */
/*   Updated: 2024/10/14 15:17:06 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

time_t	get_time_in_ms(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) + (tv.tv_usec));
}

// void print_action(int action)
// {
//     if(action == 1)
//         printf("Eatings");
//     if(action == 2)
//         printf("Sleeping");
//     if(action == 3)
//         printf("Thinking");
// }


// typedef struct s_waiter
// {
// 	unsigned int		philo_count;
// 	unsigned int		time_to_die;
// 	unsigned int		time_to_eat;
// 	unsigned int		time_to_sleep;
// 	bool				is_dead;
//     pthread_t			*threads;
//     pthread_mutex_t		*print_mutex;
// 	t_philo				**philos;
// }					t_waiter;

// void free_waiter(t_waiter *waiter)
// {
//     // if(waiter->threads != NULL)
//     //     free(threads)
//     // if(waiter->print_mutex)
//     //     free(waiter->print_mutex);
//     // if(waiter->threads)
//     //     free(waiter->threads);
//     if(waiter)
//         free(waiter);
// }