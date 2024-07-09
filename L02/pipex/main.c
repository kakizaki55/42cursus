/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/09 20:18:54 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pipex.h"

__attribute__((destructor))
static void	destructor(void) {
	// ft_printf("n\n------------------------------------------------------\n");
	// system ("bash ./cleanup.sh");
	ft_printf("\n------------------------------------------------------\n");
	system ("leaks -q --groupByType pipex");
}

void throw_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

char *find_path(char *cmd, char *envp[])
{
	char **path_arr;
	char *path_str;
	char *path;
	int i;

	i = 0;
	while (envp[i])
	{
		if(ft_strnstr(envp[i], "PATH=", 5))
		{
			path_str = ft_strnstr(envp[i], "PATH=", 5);
			break ;
		}
		i++;
	}
	path_str = ft_strtrim(path_str, "PATH=");
	path_arr = ft_split(path_str, ':');
	i = 0;
	for(int i = 0; path_arr[i]; i++)
	{
		// ft_printf("all paths are:%s\n", path_arr[i]);
	}

	while (path_arr[i])
	{
		// ft_printf("paths:%s\n", path_arr[i]);
		if(ft_strncmp(&path_arr[i][ft_strlen(path_arr[i]) - 1], "/", 1))
			path = ft_strjoin(path_arr[i], "/");
		// ft_printf("paths:%s\n", path);
		path = ft_strjoin(path, cmd);
		// free(cmd);
		// ft_printf("paths:%s\n", path);
		if(!access(path, X_OK))
		{
			return (free(path_str), free(path_arr), path);
		}
		free(path);
		i ++;
	}
	return (NULL);
}

int execute_cmd(char *cmd, char*envp[])
{
	char **cmd_arr;
	char **envs;
	char *path;

	cmd_arr = ft_split(cmd, ' ');
	path = find_path(cmd_arr[0], envp);
	if(!path)
		throw_error("could not find command");

	if(execve(path, &cmd_arr[0], envp) == -1)
	{
		throw_error("execve went wrong");
	}
	return (0);
}

int	main(int argc, char *argv[],  char *envp[])
{
	char **cmd_arr;
	char *input;
	char *output;

	cmd_arr = parse_cmd(argc, argv);
	input = argv[1];
	output = argv[argc -1];

	int 	pipefd[2];
	pid_t 	child_pid;

	pipe(pipefd);
	int filein = open(input, O_RDONLY);
	if(filein == -1)
	{
		throw_error("input file not found");
	}
	// child_pid = fork();
	if(!fork())
	{
		ft_printf("child_pid:%d\n", child_pid);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO); // this connects the write end of the pipe
		dup2(filein, STDIN_FILENO); // this connects the write end of the pipe

		execute_cmd(cmd_arr[0], envp);
		close(pipefd[1]);
	}

	waitpid(-1, NULL, 0);
	// child_pid = fork();
	if(!fork())
	{
		int fileout = open (output, O_WRONLY);
		if(fileout == -1)
		{
			throw_error("output file not found");
		}
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fileout, STDOUT_FILENO);
		execute_cmd(cmd_arr[0], envp);
		close(pipefd[0]);
	}

	// // ft_printf("child_pid:%d\n", child_pid);
	// return (0);
	// // {
	// // 	throw_error("second child failed");
	// // 	//throw error
	// // }

	// waitpid(-1, NULL, 0);
	// close(pipefd[0]);
	// close(pipefd[1]);
	// free_all(cmd_arr);
	return (0);



	// ---checking to see if the argv are parsed correctly---
	// ft_printf("input:%s\noutput%s\n", input, output);
	// for (int i = 0; cmd_arr[i]; i++)
	// {
	// 	ft_printf("cmd: %s\n", cmd_arr[i]);
	// }
	// for (int i = 0; envp[i]; i++)
	// {
	// 	ft_printf("env: %s\n", envp[i]);
	// }


	// ---macking sure get_next_line is wokring as intended----
	// while()
	// ft_printf("input:%s\noutput%s\n", input, output);

	// int i = 0;
	// int fd = open("./files/infile", O_RDONLY);
	// char *str;
	// str = "hello";
	// while (i < 5)
	// {
	// 	str = get_next_line(fd);
	// 	ft_printf("[%d]:%s\n", i, str);
	// 	free(str);
	// 	i++;
	// }
	// close(fd);
	// ft_printf("hello world\n");

}
