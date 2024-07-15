/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:51:25 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/15 17:29:32 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

__attribute__((destructor)) static void destructor(void)
{
	// ft_printf("\n------------------------------------------------------\n");
	// system ("valgrind -q pipex");
	// ft_printf("\n------------------------------------------------------\n");
	// system ("cat test.txt; rm test.txt");
}

int	execute_cmd(char *cmd, char *envp[])
{
	char	**cmd_arr;
	char	**envs;
	char	*path;

	cmd_arr = ft_split(cmd, ' ');
	free(cmd);
	path = find_path(cmd_arr[0], envp);

	if (!path)
	{
		// ft_printf("!!!execve error!!");
		free_all(cmd_arr);
		free(path);
		perror("command path not found");
		exit(127);
	}

	if (execve(path, cmd_arr, envp) == -1)
	{
		// ft_printf("!!!execve error!!");
		free_all(cmd_arr);
		free(path);
		perror("execution went worng");
		exit(EXIT_FAILURE);
	}

	return (free_all(cmd_arr), free(path), 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**cmd_arr;
	char	*input;
	char	*output;
	int		pipefd[2];
	pid_t	child_pid;
	int		filein;
	int		fileout;

	if(argc != 5)
	{
		errno = EINVAL;
		perror("bash");
		exit(EXIT_FAILURE);
	}

	cmd_arr = parse_cmd(argc, argv);
	input = argv[1];
	output = argv[argc - 1];
	pipe(pipefd);

	child_pid = fork();
	if (child_pid == 0)
	{
		filein = open(input, O_RDONLY);
	if (filein == -1)
	{
		free_all(cmd_arr);
		throw_error("could not find input file");
	}
		// ft_printf("child_pid:%d\n", child_pid);
		close(pipefd[0]); // This closes the read end of the pipe
		dup2(pipefd[1], STDOUT_FILENO);
		// this connects the write end of the pipe
		dup2(filein, STDIN_FILENO);
		// this makes filein the input for this fork
		// ft_printf("cmd is%s", cmd_arr[0]);
		// i need to figure out a way to free the 
		execute_cmd(cmd_arr[0], envp); // exicute the command
		close(pipefd[1]);              // closing the write end of the pipe
	}

	int status;
	int waitfailure = 1;
	status = 0;

	// if(waitpid(child_pid, &status, 0) == -1)
	// 	waitfailure = 0;


	
	if(waitpid(child_pid, &status, 0) == -1)
	{
		free_all(cmd_arr);
		exit(EXIT_FAILURE);	
	}
	// if(waitpid(child_pid, &status, 0) == -1)
	// 	exit(EXIT_FAILURE);




	if (child_pid > 0);
	{
		fileout = open(output, O_WRONLY | O_CREAT | O_TRUNC , 0644 );
		if (fileout == -1)
		{
			free_all(cmd_arr);
			throw_error("output file not found");
		}
		close(pipefd[1]); // this closes the write end of the pipe
		dup2(pipefd[0], STDIN_FILENO);
		// this connects the read end of the pipe for this fork
		dup2(fileout, STDOUT_FILENO);
		// this makes fileout the output for this fork
		char *cmd = ft_strdup(cmd_arr[1]);
		free_all(cmd_arr);
		execute_cmd(cmd, envp); // exicute the command
		close(pipefd[0]);      // closig the read end of the pipe
	}

	close(pipefd[0]);
	close(pipefd[1]);

	// if (waitfailure == 0)
	// 	exit(EXIT_FAILURE);

	// if(waitpid(-1, &status, 0) == -1)
	// 	exit(status);
	// waitpid(-1, &status, 0);

	if(status > 0)
	{
		perror("there was an error");
		// free_all(cmd_arr);
		exit(WEXITSTATUS(status));
	}
	
	// free_all(cmd_arr);



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
	return (0);
}
