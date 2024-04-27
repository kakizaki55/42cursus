/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:31:38 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/27 11:17:40 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include "libft.h"
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
