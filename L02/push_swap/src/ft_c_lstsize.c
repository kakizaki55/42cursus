/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:06:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/09 21:31:44 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

int	ft_c_lstsize(t_c_list *lst)
{
	int	res;
	void *current;

	current = lst;
	res = 1;
	while (lst != NULL && current != lst)
	{	
		lst = lst->next;
		res++;
	}
	return (res);
}
