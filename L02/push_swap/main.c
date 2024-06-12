/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/12 23:12:07 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

int	main(int argc, char *argv[])
{

	t_c_list *head;

	head = NULL;

	ft_c_lstadd(&head, ft_c_lstnew(1));
	printf("%d\n", (head)->content);
	printf("head is:%p\n", (head));
	printf("next is:%p\n", (head)->next);
	printf("prev is:%p\n", (head)->prev);

	ft_c_lstadd(&head, ft_c_lstnew(2));
	printf("%d\n", (head)->content);
	printf("head is:%p\n", (head));
	printf("next is:%p\n", (head)->next);
	printf("prev is:%p\n", (head)->prev);


	ft_c_lstadd(&head, ft_c_lstnew(3));
	printf("%d\n", (head)->content);
	printf("head is:%p\n", (head));
	printf("next is:%p\n", (head)->next);
	printf("prev is:%p\n", (head)->prev);
	
	ft_c_lstadd(&head, ft_c_lstnew(4));
	printf("%d\n", (head)->content);
	printf("head is:%p\n", (head));
	printf("next is:%p\n", (head)->next);
	printf("prev is:%p\n", (head)->prev);

	ft_c_lstadd(&head, ft_c_lstnew(5));
	printf("%d\n", (head)->content);
	printf("head is:%p\n", (head));
	printf("next is:%p\n", (head)->next);
	printf("prev is:%p\n", (head)->prev);

	ft_c_lstadd(&head, ft_c_lstnew(6));
	printf("%d\n", (head)->content);
	printf("head is:%p\n", (head));
	printf("next is:%p\n", (head)->next);
	printf("prev is:%p\n", (head)->prev);

	printf("%d\n", ft_c_lstsize(&head));

	print_lst(head);
	ft_printf("---------------------\n");
	rotate(&head);
	print_lst(head);
	ft_printf("---------------------\n");
	rotate(&head);
	print_lst(head);

	ft_printf("---------------------\n");
	r_rotate(&head);
	print_lst(head);

	ft_printf("---------------------\n");
	t_c_list *poped;
	poped = ft_lstpop(&head);
	print_lst(poped);
	puts("list is at:");
	print_lst(head);
	// ft_printf("---------------------\n");
	// ft_lstpop(head);
	// print_lst(head);
}
