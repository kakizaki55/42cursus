/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizak <minokakakizak@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:21 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/25 13:35:02 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		check_for_new_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		init(char *sttc_str, char **buffer, char **result);
int		clean_up(char **sttc_str, char **buffer, char **result, int *bytes);
char	*get_new_string(int fd, char *sttc_str);
char	*get_one_line(char *str);
char	*ft_strdup(const char *str);

#endif
