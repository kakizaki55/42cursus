/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:56:57 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/09 21:33:15 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

void	ft_c_lstadd(t_c_list **lst, t_c_list *new)
{	
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev = new;
	*lst = new;
}
