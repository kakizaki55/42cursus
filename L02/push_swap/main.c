/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/09 23:36:48 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

int	main(int argc, char *argv[])
{

	t_c_list *head;

	head = ft_c_lstnew(1);
	printf("%d\n", head->content);
	printf("head is:%p\n", head);
	printf("next is:%p\n", head->next);
	printf("prev is:%p\n", head->prev);

	ft_c_lstadd(&head, ft_c_lstnew(2));
	printf("%d\n", head->content);
	printf("head is:%p\n", head);
	printf("next is:%p\n", head->next);
	printf("prev is:%p\n", head->prev);

	ft_c_lstadd(&head, ft_c_lstnew(3));
	printf("%d\n", head->content);
	printf("head is:%p\n", head);
	printf("next is:%p\n", head->next);
	printf("prev is:%p\n", head->prev);

	ft_c_lstadd(&head, ft_c_lstnew(4));
	printf("%d\n", head->content);
	printf("head is:%p\n", head);
	printf("next is:%p\n", head->next);
	printf("prev is:%p\n", head->prev);

	printf("%d\n", ft_c_lstsize(head));
	// printf("%d\n", head->next->content);
	
	int ARG[] = {1, 2, 3, 4, 5};
	int i;
	i = 0;
	while(ARG[i])
	{
		printf("ARG[i]:%d\n", ARG[i]);
		i++;
	}
	return (0);
}
