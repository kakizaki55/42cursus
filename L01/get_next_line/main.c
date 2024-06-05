/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:24 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/25 18:10:23 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <fcntl.h>
__attribute((destructor)) static void destructor(void)
{
	system("leaks -q --list --fullStacks a.out");
}

int	main(void)
{
	int		fd;
	// int		fd2;
	char	*line;
	int		i;
	int		print_len;

	fd = open ("test.txt", O_RDONLY);
	// fd2  = open ("test2.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	i = 1;
	print_len = 10;
	while (i <= print_len)
	{
		line = get_next_line(fd);
		printf("line [%d]:%s", fd, line);
		printf("line [%d]:%zu\n", fd, ft_strlen(line));
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%d]:%s", fd2, line);
		// printf("line [%d]:%zu\n", fd2, ft_strlen(line));
		// free(line);
		i++;
	}
	return (0);
}
