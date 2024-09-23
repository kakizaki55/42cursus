/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:16:09 by mkakizak          #+#    #+#             */
/*   Updated: 2024/09/23 17:20:35 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	*convert_to_int(char **array, int len, t_vars *vars)
{
	int	i;
	int	*res;
	int	temp;

	i = 0;
	res = ft_calloc(sizeof(int), len);
	if (res == NULL)
		return (NULL);
	while (array[i])
	{
		res[i] = ft_atoi(array[i]);
		if (res[i] >= 50)
			vars->height_offest = 10;
		i++;
	}
	return (free_all(array), res);
}

int	get_file_length(char *file_path)
{
	int		res;
	int		fd;
	char	*str;

	file_path = ft_strjoin("test_maps/", file_path);
	if (file_path == NULL)
		return (0);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (free(file_path), 0);
	free(file_path);
	res = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		res++;
	}
	close(fd);
	return (res);
}

int	check_file_fdf(char *filename)
{
	int	res;
	int	len;

	if (filename == NULL)
		return (-1);
	len = ft_strlen(filename);
	if (len < 4)
		return (-1);
	res = ft_strncmp(filename + len - 4, ".fdf", 4);
	return (res);
}

void	init_parse(char *file_path, t_vars *vars, int *fd)
{
	if (!ft_strncmp(file_path, "42.fdf", 6))
		vars->height_offest = 10;
	if (file_path == NULL)
		distroy_and_exit(vars, EXIT_FAILURE, "Please put in a file name\n");
	if (check_file_fdf(file_path) != 0)
		distroy_and_exit(vars, EXIT_FAILURE, "Not .fdf file\n");
	vars->col = get_file_length(file_path);
	if (vars->col == 0)
		distroy_and_exit(vars, EXIT_FAILURE, "Failed to get file length");
	vars->matrix = (int **)ft_calloc(sizeof(int *), vars->col + 1);
	if (vars->matrix == NULL)
		distroy_and_exit(vars, EXIT_FAILURE, "Failed to allocate matrix block");
	file_path = ft_strjoin("test_maps/", file_path);
	if (file_path == NULL)
		distroy_and_exit(vars, EXIT_FAILURE, "Failed to create file path");
	*fd = open(file_path, O_RDONLY);
	free(file_path);
	if (*fd == -1)
		distroy_and_exit(vars, EXIT_FAILURE, "Failed to open file");
}

void	parse_map(char *file_path, t_vars *vars)
{
	int		i;
	int		fd;
	char	*str;
	char	**array;

	init_parse(file_path, vars, &fd);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str)
		{
			array = ft_split(str, ' ');
			if (array == NULL)
				distroy_and_exit(vars, EXIT_FAILURE, "Failed to parse map");
			vars->row = str_arr_length(array);
			vars->matrix[i] = convert_to_int(array, vars->row, vars);
			free(str);
		}
		else
			break ;
		i++;
	}
	close(fd);
	return ;
}
