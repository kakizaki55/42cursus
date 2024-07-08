/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/08 14:25:30 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pipex.h"

__attribute__((destructor))
static void	destructor(void) {
	system ("leaks -q --groupByType pipex");
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
	
	child_pid = fork();
	int filein = open(input, O_RDONLY);
	if(filein == -1)
	{
		// thorw error
	}
	if(child_pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO); // this connects the write end of the pipe
		dup2(filein, STDIN_FILENO); // this connects the write end of the pipe
		// execve("/usr/bin/", &cmd_arr[0], envp);
		execlp(cmd_arr[0], cmd_arr[0]);
		// close(filein);
	}
	else
	{
		//throw error
	}

	child_pid = fork();
	int fileout = open (output, O_WRONLY);
	if(fileout == -1)
	{
		// thorw error
	}
	if(child_pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fileout, STDOUT_FILENO);
		execlp(cmd_arr[1], cmd_arr[1]);
		close(fileout);
		
	}else
	{
		//throw error
	}

	close(pipefd[0]);
	close(pipefd[1]);

	waitpid(child_pid, NULL, 0);
	// waitpid(child_pid, NULL, 0);
	free_all(cmd_arr);

	return (0);


	// ---checking to see if the argv are parsed correctly---
	ft_printf("input:%s\noutput%s\n", input, output);
	for (int i = 0; cmd_arr[i]; i++)
	{
		ft_printf("cmd: %s\n", cmd_arr[i]);
	}
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
