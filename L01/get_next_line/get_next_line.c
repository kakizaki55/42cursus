/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 22:18:06 by minokakakiz      ###   ########.fr       */
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
	result[i] = '\0';
	if (str != NULL)
        free(str); 
	return (result);
}


char	*get_next_line(int fd)
{
	static char	*sttc_str;
	char 		*result;
	// static int 	prev_fd = -1;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// if (prev_fd != fd && prev_fd != -1)
    // {
    //     free(sttc_str);
    //     sttc_str = NULL;
    // }
    // prev_fd = fd;

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
