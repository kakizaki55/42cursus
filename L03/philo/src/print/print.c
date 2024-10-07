/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:31:07 by minoka            #+#    #+#             */
/*   Updated: 2024/10/06 17:03:40 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


int safe_print(t_waiter *waiter, const char *format, ...)
{
    va_list args;
    int result;

    if (waiter == NULL || waiter->print_mutex == NULL)
        return -1;

    pthread_mutex_lock(waiter->print_mutex);

    va_start(args, format);
    result = printf(format, args);
    va_end(args);

    pthread_mutex_unlock(waiter->print_mutex);

    return result;
}