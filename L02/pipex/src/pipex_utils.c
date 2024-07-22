/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:26:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/16 19:08:47 by mkakizak         ###   ########.fr       */
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
	free(str_arr);
	return (0);
}

void	throw_error(char *message, int exit_status, int error_number)
{	
	if(error_number)
		errno = error_number;
	perror(message);
	// free(message);
	exit(exit_status);
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
			free_all(res);
		}
		i++;
	}
	return (res);
}


// char *check_path(char *path_str, char **path_arr, char *cmd)
// {
// 	char 	*path;
// 	int 	i;
// 	char 	*tmp;

// 	i = 0;
// 	while (path_arr[i])
// 	{	
// 		if(cmd[0] == '/')
// 		{
// 			if (!access(cmd, X_OK))
// 				return (free(path_str), free_all(path_arr), cmd);
// 			else
// 				return (free(path_str), free_all(path_arr), NULL);
// 		}
// 		if (ft_strncmp(&path_arr[i][ft_strlen(path_arr[i]) - 1], "/", 1))
// 			path = ft_strjoin(path_arr[i], "/");

// 		tmp = ft_strdup(path);
// 		free(path);
//  		path = ft_strjoin(tmp, cmd);
// 		if (!access(path, X_OK))
// 			return (free(path_str), free_all(path_arr), path);
// 		free(tmp);
// 		free(path);
// 		i++;
// 	}

// 	return (NULL);
// }

char	*find_path(char *cmd, char *envp[])
{
	char **path_arr;
	char *path_str;
	char *path;
	int i;

	if(!cmd || !cmd[0])
		return (NULL);

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
		if(cmd[0] == '/')
		{
			if (!access(cmd, X_OK))
				return (free(path_str), free_all(path_arr), cmd);
			else
				return (free(path_str), free_all(path_arr), NULL);
		}
		if (ft_strncmp(&path_arr[i][ft_strlen(path_arr[i]) - 1], "/", 1))
			path = ft_strjoin(path_arr[i], "/");

		char *tmp = ft_strdup(path);
		free(path);
 		path = ft_strjoin(tmp, cmd);

		if (!access(path, X_OK))
		{
			return (free(path_str), free_all(path_arr), path);
		}

		free(tmp);
		free(path);
		i++;
	}
	return (free(path_str), free_all(path_arr), NULL);
}
