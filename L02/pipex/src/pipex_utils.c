/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:26:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/08 13:38:17 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pipex.h"

int free_all(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	// free(str_arr[i]);
	free(str_arr);
	return (0);
}

char **parse_cmd(int argc, char *argv[])
{
	int i;
	int len;
	char **res;
	if(argc <= 1)
		return(NULL);

	i = 0;
	len = argc - 3;
	res = ft_calloc(sizeof(char *), len + 1);
	if(!res)
		return(NULL);
	res[len] = NULL;
	while(i < len)
	{
		res[i] = ft_strdup(argv[i + 2]);
		if(res[i] == NULL)
		{
			//do cleanup 
		}
		i++;
	}
	return (res);
}