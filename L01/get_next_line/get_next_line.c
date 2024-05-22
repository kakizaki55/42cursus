/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/21 23:37:18 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int	check_for_new_line(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*join_buffers(int fd, char *res)
{
	char	*temp;
	int		len;
	int 	offset;

	offset = BUFFER_SIZE;
	if(res[0] != '\0')
		offset = ft_strlen(res) - BUFFER_SIZE;

	len = 0;
	temp = "";
	temp = ft_strjoin(temp, res);


	while (check_for_new_line(res) == 0)
	{
		read(fd, res, BUFFER_SIZE);
		temp = ft_strjoin(temp, res);
		len += BUFFER_SIZE;
	}
	len += check_for_new_line(res) + offset;
	// printf("len is:%d", len);
	return (ft_strldup(ft_strjoin(temp, res), len));
}


char	*get_next_line(int fd)
{
	static char	res[BUFFER_SIZE];
	char 		*temp;
	int			start;
	int			end;

	start = 0;

	if(res[0] == '\0')
		read(fd, res, BUFFER_SIZE);
	else
	{	
		// printf("here:%s\nstart is:%d\n", res, start);
		start = check_for_new_line(res) + 1;
		// printf("here:%s\nstart is:%d\n", res, start);
	}

	if (check_for_new_line(&res[start + 1]) != 0)
	{
		read(fd, res, BUFFER_SIZE);
		// printf("here: %s \nstart is: %d\n", res, start);
		return (ft_strldup(&res[start], check_for_new_line(&res[start + 1])));
	}
	else
	{
		return (join_buffers(fd, &res[start]));
	}
	// printf("buffer is: %d\n", BUFFER_SIZE);
	// printf("res is: %s\n", res);
	return (res);
}
