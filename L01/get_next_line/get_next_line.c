/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 20:20:12 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*trim_string(int n, char *str)
{
	int i;
	int len;
	char *result;

	if(n == 0 || str == NULL)
		return (NULL);

	len = ft_strlen(str) - n;

	i = 0;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (i <= len)
	{
		result[i] = str[i + n];
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

	sttc_str = get_new_string(fd, sttc_str);
	result = get_one_line(sttc_str);
	sttc_str = trim_string(ft_strlen(result), sttc_str);
	return (result);
}
