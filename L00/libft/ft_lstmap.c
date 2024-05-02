/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:17:04 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/02 21:25:35 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*start;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (node == NULL)
		return (NULL);
	start = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if (node->next == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		node = node->next;
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

