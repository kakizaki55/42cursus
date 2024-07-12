/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:51:25 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/12 23:28:10 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pipex.h"

__attribute__((destructor)) static void destructor(void)
{
	// ft_printf("\n------------------------------------------------------\n");
	// system ("valgrind -q pipex");
	// ft_printf("\n------------------------------------------------------\n");
	// system ("cat outfile; rm outfile");
}

int	execute_cmd(char *cmd, char *envp[])
{
	char	**cmd_arr;
	char	**envs;
	char	*path;

	cmd_arr = ft_split(cmd, ' ');
	path = find_path(cmd_arr[0], envp);

	// ft_printf("path is:%s\n", path);
	// ft_printf("is it even getting here?\n");

	// for(int i = 0; cmd_arr[i]; i++)
	// 	ft_printf("%s\n", cmd_arr[i]);

	if (!path)
	{
		free_all(cmd_arr);
		// throw_error("could not find command");
		exit(127);
	}

	// ft_printf("is it getting here?\n");

	if (execve(path, cmd_arr, envp) == -1)
	{
		ft_printf("!!!execve error!!");
		// throw_error("execve went wrong");
	}

	// exit(256);
	return (0);
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

	cmd_arr = parse_cmd(argc, argv);
	input = argv[1];
	output = argv[argc - 1];
	pipe(pipefd);



	fileout = open(output, O_WRONLY | O_CREAT , 0777 );
	if (fileout == -1)
	{
		throw_error("output file not found");
	}
	if (!fork())
	{
		close(pipefd[1]); // this closes the write end of the pipe
		dup2(pipefd[0], STDIN_FILENO);
		// this connects the read end of the pipe for this fork
		dup2(fileout, STDOUT_FILENO);
		// this makes fileout the output for this fork
		execute_cmd(cmd_arr[1], envp); // exicute the command
		close(pipefd[0]);      // closig the read end of the pipe
	}



	filein = open(input, O_RDONLY);
	if (filein == -1)
	{
		throw_error("input file not found");
	}
	if (!fork())
	{
		// ft_printf("child_pid:%d\n", child_pid);
		close(pipefd[0]); // This closes the read end of the pipe
		dup2(pipefd[1], STDOUT_FILENO);
		// this connects the write end of the pipe
		dup2(filein, STDIN_FILENO);
		// this makes filein the input for this fork
		// ft_printf("cmd is%s", cmd_arr[0]);
		execute_cmd(cmd_arr[0], envp); // exicute the command
		close(pipefd[1]);              // closing the write end of the pipe
	}

	int status;
	int status2;

	close(pipefd[0]);
	close(pipefd[1]);
	if(waitpid(-1, &status, 0) == -1)
		exit(EXIT_FAILURE);
	if(waitpid(-1, &status2, 0) == -1)
		exit(EXIT_FAILURE);


	// if(waitpid(-1, &status, 0) == -1)
	// 	exit(status);
	// waitpid(-1, &status, 0);
	free_all(cmd_arr);
	ft_printf("does it get here end of main exsit status: %d\n", status);
	if (WIFEXITED(status) || WIFEXITED(status2)) 
	{
        printf("Exit status was %d\n", WIFEXITED(status));
		if(status)
			exit(WEXITSTATUS(status));
		if(status2)
			exit(WEXITSTATUS(status2));
        // return(status);
    }
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
