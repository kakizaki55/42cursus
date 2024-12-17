/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:14:24 by minoka            #+#    #+#             */
/*   Updated: 2024/10/10 14:16:24 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	join_threads(t_waiter *waiter)
{
	int i;
	i = 0;
	while(i < waiter->philo_count)
	{
        pthread_join(waiter->philos[i]->thread, NULL);
		i++;
    }
}
