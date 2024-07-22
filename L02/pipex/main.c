/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:51:25 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/16 19:07:12 by mkakizak         ###   ########.fr       */
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
	char	*path;
	// char    temp[ft_strlen(cmd)];
	
	// if(!ft_strnstr(cmd, "awk", ft_strlen(cmd)))
	// {
		cmd_arr = ft_split(cmd, ' ');
		// ft_strlcpy(temp, cmd, ft_strlen(cmd));
		free(cmd);
		path = find_path(cmd_arr[0], envp);
	// }
	if (!path)
	{
		free_all(cmd_arr);
		free(path);
		// char *str = ft_strdup("checking to see if this works");
		throw_error("bash: command not found", 127, 0);
	}

	if (execve(path, cmd_arr, envp) == -1)
	{
		free_all(cmd_arr);
		free(path);
		throw_error("bash: execution went worng", EXIT_FAILURE, 0);
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
		throw_error("bash", EXIT_FAILURE, EINVAL);

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
			throw_error("bash: could not find input file", EXIT_FAILURE, 0);
		}
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(filein, STDIN_FILENO);
		execute_cmd(cmd_arr[0], envp);
		close(pipefd[1]);
		close(filein);
	}

	int status;
	// int waitfailure = 1;
	status = 0;

	if(waitpid(child_pid, &status, 0) == -1)
	{
		free_all(cmd_arr);
		exit(EXIT_FAILURE);	
	}

	if (child_pid > 0)
	{
		fileout = open(output, O_WRONLY | O_CREAT | O_TRUNC , 0644 );
		if (fileout == -1)
		{
			free_all(cmd_arr);
			throw_error("bash: output file not found", EXIT_FAILURE, 0);
		}
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fileout, STDOUT_FILENO);
		char *cmd = ft_strdup(cmd_arr[1]);
		free_all(cmd_arr);
		execute_cmd(cmd, envp);
		close(pipefd[0]);
		close(fileout);
	}

	close(pipefd[0]);
	close(pipefd[1]);

	if(status > 0)
	{
		perror("there was an error");
		free_all(cmd_arr);
		exit(WEXITSTATUS(status));
	}
	
	return (0);
}
