/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:35:28 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/03 13:34:01 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pointer;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		pointer = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pointer;
	}
	*lst = NULL;
}
