/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:10:57 by minoka            #+#    #+#             */
/*   Updated: 2024/12/27 15:11:11 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_forks *get_fork_by_index(t_forks *head, int index)
{
    t_forks *current = head;
    int i = 0;

    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }
    return current;
}