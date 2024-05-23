/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:17 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 19:26:26 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_for_new_line(char *string)
{
	int	i;

	if(string == NULL)
		return (0);
	
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
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
	}
	free (buffer);
	return (sttc_str);
}