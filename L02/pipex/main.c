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

// __attribute__((destructor)) static void destructor(void)
// {
// 	// ft_printf("\n------------------------------------------------------\n");
// 	// system ("valgrind -q pipex");
// 	// ft_printf("\n------------------------------------------------------\n");
// }
// Could put a check in here to see if the command is awk.

int	execute_cmd(char *cmd, char *envp[])
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = ft_split(cmd, ' ');
	free(cmd);
	path = find_path(cmd_arr[0], envp);
	if (!path)
	{
		free_all(cmd_arr);
		free(path);
		throw_error("bash: command not found", 127, 0);
	}
	if (execve(path, cmd_arr, envp) == -1)
	{
		free_all(cmd_arr);
		free(path);
		throw_error("bash: execution went worng", EXIT_FAILURE, 0);
	}
	return (0);
}

int	child_process(char *input, char **cmd_arr, int *pipefd, char **envp)
{
	int	infile_fd;

	infile_fd = open(input, O_RDONLY);
	if (infile_fd == -1)
	{
		free_all(cmd_arr);
		throw_error("bash: could not find input file", EXIT_FAILURE, 0);
	}
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	execute_cmd(cmd_arr[0], envp);
	return (0);
}

int	parent_process(char *output, char **cmd_arr, int *pipefd, char **envp)
{
	int		outfile_fd;
	char	*cmd;

	outfile_fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		free_all(cmd_arr);
		throw_error("bash: output file not found", EXIT_FAILURE, 0);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	cmd = ft_strdup(cmd_arr[1]);
	free_all(cmd_arr);
	execute_cmd(cmd, envp);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**cmd_arr;
	char	*input;
	char	*output;
	int		pipefd[2];
	pid_t	child_pid;
	int		status;
	if (argc != 5)
		throw_error("bash", EXIT_FAILURE, EINVAL);
	cmd_arr = parse_cmd(argc, argv);
	input = argv[1];
	output = argv[argc - 1];

	pipe(pipefd);

	if (fork() == 0)
		child_process(input, cmd_arr, pipefd, envp);

	child_pid = fork();
	if (child_pid == 0)
		parent_process(output, cmd_arr, pipefd, envp);

	if (waitpid(child_pid, &status, 0) == -1)
	{
		free_all(cmd_arr);
		exit(EXIT_FAILURE);
	}
	waitpid(-1, NULL, 0);
	if(status > 0)
	{
		free_all(cmd_arr);
		exit(WEXITSTATUS(status));
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
