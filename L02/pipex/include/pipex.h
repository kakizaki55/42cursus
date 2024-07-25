/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:14 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/25 13:57:22 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

# define INPUT 0
# define OUTPUT 1

int		free_all(char **str_arr);
void	throw_error(char *message, int exit_status, int error_number);
char	**parse_cmd(int argc, char *argv[]);
char	*validate_path(char **path_arr, char *cmd);
char	*find_path(char *cmd, char *envp[]);

char	**cmd_split(char const *s, char c);

#endif