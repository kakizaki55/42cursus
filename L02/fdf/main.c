/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/02 19:52:10 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	int fd;
	char *file_path;
	if(argc != 2)
		return (1);

	file_path = ft_strjoin("test_maps/", argv[1]);

	fd = open(file_path, O_RDONLY);

	int bool = TRUE;
	for (int i = 0; bool; i++)
	{
		char *str = get_next_line(fd);
		if(str)
			ft_printf("%s\n", str);
		else
			bool = FALSE;
	}
	ft_printf("hello there just checking\n");
	return (0);
}
