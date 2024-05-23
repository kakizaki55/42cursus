/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 21:44:31 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*trim_string(int n, char *str)
{
	int i;
	int len;
	char *result;

	if(n == 0 || str == NULL)
	{
		free(str);
		return (NULL);
	}

	len = ft_strlen(str) - n;
	
	i = 0;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = str[n + i];
		i++;
	}
	free(str);
	result[i] = '\0';
	return (result);
}


char	*get_next_line(int fd)
{
	static char	*sttc_str;
	char 		*result;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	sttc_str = get_new_string(fd, sttc_str);
	if(sttc_str == NULL)
		return (NULL);
	result = get_one_line(sttc_str);
	if(result == NULL)
		return (NULL);
	sttc_str = trim_string(ft_strlen(result), sttc_str);
	if(sttc_str == NULL)
		return (NULL);
	return (result);
}
