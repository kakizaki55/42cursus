/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:26:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/11 18:06:42 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

int	free_all(char **str_arr)
{
	int	i;

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

void	throw_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

char	**parse_cmd(int argc, char *argv[])
{
	int		i;
	int		len;
	char	**res;

	if (argc <= 1)
		return (NULL);
	i = 0;
	len = argc - 3;
	res = ft_calloc(sizeof(char *), len + 1);
	if (!res)
		return (NULL);
	res[len] = NULL;
	while (i < len)
	{
		res[i] = ft_strdup(argv[i + 2]);
		if (res[i] == NULL)
		{
			// do cleanup
		}
		i++;
	}
	return (res);
}

char	*find_path(char *cmd, char *envp[])
{
	char **path_arr;
	char *path_str;
	char *path;
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path_str = ft_strnstr(envp[i], "PATH=", 5);
			break ;
		}
		i++;
	}
	path_str = ft_strtrim(path_str, "PATH=");
	path_arr = ft_split(path_str, ':');
	i = 0;

	while (path_arr[i])
	{
		if (ft_strncmp(&path_arr[i][ft_strlen(path_arr[i]) - 1], "/", 1))
			path = ft_strjoin(path_arr[i], "/");

		path = ft_strjoin(path, cmd);
		if (!access(path, X_OK))
		{
			return (free(path_str), free(path_arr), path);
		}
		free(path);
		i++;
	}
	return (NULL);
}
