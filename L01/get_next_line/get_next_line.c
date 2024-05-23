/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 19:39:34 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char *get_one_line(char *str)
{
	int len;
	int i;
	char *result;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
	{
		len++;
	}

	printf("len is:%d\n", len);

	i = 0;
	result = malloc(sizeof(char) * len + 2);
	if (result == NULL)
		return (NULL);
	while (i <= len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*sttc_str;
	char 		*result;

	sttc_str = get_new_string(fd, sttc_str);
	// at this poit there is a garented new line charater in static string
	result = get_one_line(sttc_str);
	printf("line is :%s",result);

	return (result);
}
