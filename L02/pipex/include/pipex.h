/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:14 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/12 22:21:11 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>

int		free_all(char **str_arr);
void	throw_error(char *message);
char	**parse_cmd(int argc, char *argv[]);
char	*find_path(char *cmd, char *envp[]);

#endif