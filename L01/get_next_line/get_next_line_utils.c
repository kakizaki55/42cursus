/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizak <minokakakizak@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:17 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/24 13:45:46 by minokakakiz      ###   ########.fr       */
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
char *ft_strdup(const char *str) 
{
    char *dup;
    int len;
    int i;

    len = ft_strlen(str);
    dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (str[i]) {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}