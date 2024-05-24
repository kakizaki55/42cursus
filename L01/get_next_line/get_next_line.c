/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizak <minokakakizak@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/24 23:52:51 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_strjoin(char *sttc_str, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(sttc_str) + ft_strlen(buffer) + 1) * sizeof(char));
	if (res == NULL)
	{
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
	return (free(sttc_str), res);
}

char *get_new_string(int fd, char *sttc_str)
{
	char	*buffer;
	int		bytes;
	char	*result;

	bytes = 1;
	if(sttc_str == NULL)
		result = ft_strdup("");
	else
		result = ft_strdup(sttc_str);
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buffer == NULL)
	{
		free(result);
		return (NULL);
	}

	while(check_for_new_line(result) == 0 && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if(bytes == -1)
		{
			free(sttc_str);
			free(result);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		result = ft_strjoin(result, buffer);
		if(result == NULL)
		{
			free (buffer);
			return(NULL);
		}
	}
	free(sttc_str);
	sttc_str = ft_strdup(result);
	free(result);
	free(buffer);
	if(bytes ==  0 && *sttc_str == '\0')
	{
		free(sttc_str);
		return (NULL);
	}
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
	{
		free(str);
		return (NULL);
	}
	while (i < len)
	{
		result[i] = str[n + i];
		i++;
	}
	result[i] = '\0';
	return (free(str), result);
}

char	*get_next_line(int fd)
{
	static char	*sttc_str;
	char 		*result;

	if(BUFFER_SIZE <= 0)
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
