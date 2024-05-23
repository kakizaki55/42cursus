/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:24 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 18:51:39 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	line = get_next_line(fd);
	// printf("line is:%s\n", line);
	// printf("line length:%zu\n", ft_strlen(line));
	// line = get_next_line(fd);
	// printf("line is:%s\n", line);
	// printf("line length:%zu\n", ft_strlen(line));
	// line = get_next_line(fd);
	// printf("line is:%s\n", line);
	// printf("line length:%zu\n", ft_strlen(line));
	// line = get_next_line(fd);
	// printf("line is:%s\n", line);
	// printf("line length:%zu\n", ft_strlen(line));
	return (0);
}
