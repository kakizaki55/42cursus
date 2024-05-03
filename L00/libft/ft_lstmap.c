/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:17:04 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/03 13:36:36 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	start = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	node->next = NULL;
	return (start);
}
// int main(void)
// {
// 	t_list *l = lstnew(strdup(" 1 2 3 "));
// 	t_list *ret;

// 	l->next = lstnew(strdup("ss"));
// 	l->next->next = lstnew(strdup("-_-"));
// 	ft_lstmap(l,NULL, NULL);
// }

