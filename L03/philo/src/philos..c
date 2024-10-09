/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos..c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:33 by minoka            #+#    #+#             */
/*   Updated: 2024/10/09 13:32:05 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void *philo(void *arg) {
    t_waiter *waiter = (t_waiter *)arg;
    // Philosopher logic here
    safe_print(waiter, "Philosopher is thinking\n");
    return NULL;
}