/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:06:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/09 23:34:58 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

int	ft_c_lstsize(t_c_list *lst)
{
	int	res;
	void *current;


	current = &lst;
	printf("%p",current); fflush(stdout);
	res = 1;
	while (1)
	{	
		lst = lst->next;
		printf("%p",lst->next); fflush(stdout);
		if((lst->next) == current)
		{
			break ;
		}
		res++;
	}
	return (res);
}
