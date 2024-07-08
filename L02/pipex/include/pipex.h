/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:14 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/07 13:44:47 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PIPEX_H
# define PIPEX_H
#include <fcntl.h>

int free_all(char **str_arr);
char **parse_cmd(int argc, char *argv[]);


#endif