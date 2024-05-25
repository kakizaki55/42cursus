/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizak <minokakakizak@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:24 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/25 13:34:00 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

#include "get_next_line.h"
#include <fcntl.h>

__attribute((destructor)) static void destructor(void)
{
	system("leaks -q --list --fullStacks a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		print_len;

	fd = open ("test.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	i = 1;
	print_len = 8;
	while (i <= print_len)
	{
		line = get_next_line(fd);
		printf("line [%d]:%s", i, line);
		printf("line [%d]:%zu\n", i, ft_strlen(line));
		free(line);
		i++;
	}
	return (0);
}
