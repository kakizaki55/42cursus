/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/21 16:20:26 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"
int check_for_new_line(char *string)
{
	int i;
	
	i = 0;
	while(string[i])
	{
		if(string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char *join_buffers(int fd, char *res)
{
	char *temp;
	int len;
	
	temp = "";
 	temp = ft_strjoin(temp, res);
	while(check_for_new_line(res) == 0)
	{	
		read(fd, res, BUFFER_SIZE);
		temp = ft_strjoin(temp, res);
		len += 10;
	}
	len += check_for_new_line(res);
	return (ft_strldup(ft_strjoin(temp, res), len));
}

char *get_next_line(int fd)
{
	static char res[BUFFER_SIZE];

	read(fd, res, BUFFER_SIZE);
	if(check_for_new_line(res) != 0)
	{
		return (ft_strldup(res, check_for_new_line(res)));
	}
	else
	{
		return (join_buffers(fd, res));
	}

	// printf("buffer is: %d\n", BUFFER_SIZE);
	// printf("res is: %s\n", res);

	return(res);
}