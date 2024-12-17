/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:26:10 by mkakizak          #+#    #+#             */
/*   Updated: 2024/12/17 15:26:23 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

time_t	get_time_in_ms(void)
{
    struct timeval	tv;
    time_t			time_in_ms;

    gettimeofday(&tv, NULL);
    time_in_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time_in_ms);
}
