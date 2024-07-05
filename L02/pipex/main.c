/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/04 20:30:00 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

__attribute__((destructor))
static void	destructor(void) {
	system ("leaks --list --fullContent pipex");
}

#include <fcntl.h>

int	main(int argc, char *argv[])
{	
	int i = 0;
	int fd = open("./files/infile", O_RDONLY);
	char *str;
	str = "hello";
	while (i < 5)
	{
		str = get_next_line(fd);
		ft_printf("[%d]:%s\n", i, str);
		free(str);
		i++;
	}
	close(fd);
	ft_printf("hello world\n");
	return (0);
}
