/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minoka <minoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:19:33 by minoka            #+#    #+#             */
/*   Updated: 2024/10/06 13:19:56 by minoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        unsigned int    i;

        i = 0;
        while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
        {
                if (s1[i] != s2[i])
                {
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                }
                i++;
        }
        return (0);
}
