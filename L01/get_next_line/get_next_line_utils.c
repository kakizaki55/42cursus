/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:17 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 22:22:31 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if(str == NULL)
		return(0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_for_new_line(char *str)
{
	int	i;

	if(str == NULL)
		return (0);
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}


char	*ft_strjoin(char *sttc_str, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	if (sttc_str == NULL || buffer == NULL)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc((ft_strlen(sttc_str) + ft_strlen(buffer) + 1) * sizeof(char));
	if (res == NULL)
	{
		free(buffer);
		free(sttc_str);
		return (NULL);
	}
	while (sttc_str[i] != '\0')
	{
		res[i] = sttc_str[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		res[i + j] = buffer[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char *get_new_string(int fd, char *sttc_str)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	if(sttc_str == NULL)
		sttc_str = "";

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buffer == NULL)
		return (NULL);

	while(check_for_new_line(sttc_str) == 0 && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if(bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		sttc_str = ft_strjoin(sttc_str, buffer);
		if(sttc_str == NULL)
		{
			free(sttc_str);
			return (NULL);
		}
	}
	free (buffer);
	return (sttc_str);
}

char *get_one_line(char *str)
{
	int len;
	int i;
	char *result;

	len = 0;
	if(str[0] == '\0')
		return (NULL);
	while (str[len] != '\0' && str[len] != '\n')
	{
		len++;
	}
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
