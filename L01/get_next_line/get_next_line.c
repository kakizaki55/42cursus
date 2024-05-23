/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:11:19 by minokakakiz       #+#    #+#             */
/*   Updated: 2024/05/23 19:16:20 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_string;
	char 		*result;

	static_string = get_new_string(fd, static_string);
	printf("%s",static_string);
	return (result);
}
