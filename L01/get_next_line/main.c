/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:24 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 20:16:20 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int 	i;
	int 	print_len;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}

	i = 1;
	print_len = 8;

	while (i <= print_len)
	{
		line = get_next_line(fd);
		printf("line [%d]:%s\n",i ,line);
		printf("line [%d]:%zu\n",i ,ft_strlen(line));
		i++;
	}
	return (0);
}
