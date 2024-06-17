/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/17 13:26:36 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{	

	t_c_list *head;

	head = NULL;
	int i = 0;
	int *args_arr;

	if(argc < 2)
		return (-1);
	
	args_arr = args_validation(argc, argv);


	print_arr(args_arr);

















//-----------------TEST----------------
	// ft_c_lstadd(&head, ft_c_lstnew(1));
	// ft_c_lstadd(&head, ft_c_lstnew(2));
	// ft_c_lstadd(&head, ft_c_lstnew(3));
	// ft_c_lstadd(&head, ft_c_lstnew(4));
	// ft_c_lstadd(&head, ft_c_lstnew(5));
	// ft_c_lstadd(&head, ft_c_lstnew(6));
	// ft_c_lstadd(&head, ft_c_lstnew(7));


	// ft_c_print_lst(head);
	// ft_c_lstclear(&head);
	// ft_c_print_lst(head);

	// print_lst(head);
//----------------------------------------

	//____________this is the testing to ake sure everything works okay_____________
	// t_c_list *head;

	// head = NULL;
	// ft_c_lstadd(&head, ft_c_lstnew(1));
	// printf("%d\n", (head)->content);
	// printf("head is:%p\n", (head));
	// printf("next is:%p\n", (head)->next);
	// printf("prev is:%p\n", (head)->prev);

	// ft_c_lstadd(&head, ft_c_lstnew(2));
	// printf("%d\n", (head)->content);
	// printf("head is:%p\n", (head));
	// printf("next is:%p\n", (head)->next);
	// printf("prev is:%p\n", (head)->prev);


	// ft_c_lstadd(&head, ft_c_lstnew(3));
	// printf("%d\n", (head)->content);
	// printf("head is:%p\n", (head));
	// printf("next is:%p\n", (head)->next);
	// printf("prev is:%p\n", (head)->prev);
	
	// ft_c_lstadd(&head, ft_c_lstnew(4));
	// printf("%d\n", (head)->content);
	// printf("head is:%p\n", (head));
	// printf("next is:%p\n", (head)->next);
	// printf("prev is:%p\n", (head)->prev);

	// ft_c_lstadd(&head, ft_c_lstnew(5));
	// printf("%d\n", (head)->content);
	// printf("head is:%p\n", (head));
	// printf("next is:%p\n", (head)->next);
	// printf("prev is:%p\n", (head)->prev);

	// ft_c_lstadd(&head, ft_c_lstnew(6));
	// printf("%d\n", (head)->content);
	// printf("head is:%p\n", (head));
	// printf("next is:%p\n", (head)->next);
	// printf("prev is:%p\n", (head)->prev);

	// printf("%d\n", ft_c_lstsize(&head));

	// print_lst(head);
	// ft_printf("---------------------\n");
	// rotate(&head);
	// print_lst(head);
	// ft_printf("---------------------\n");
	// rotate(&head);
	// print_lst(head);

	// ft_printf("---------------------\n");
	// r_rotate(&head);
	// print_lst(head);

	// ft_printf("---------------------\n");
	// t_c_list *poped;
	// poped = ft_lstpop(&head);
	// puts("poped is:");
	// print_lst(poped);
	// puts("list is at:");
	// print_lst(head);

	// ft_printf("---------------------\n");
	// poped = ft_lstpop(&head);
	// puts("poped is:");
	// print_lst(poped);
	// puts("list is at:");
	// print_lst(head);

	// ft_printf("---------------------\n");
	// print_lst(head);
	// ft_lstswap(&head);
	// puts("swap lst is:");
	// print_lst(head);
	// printf("size is:%d\n", ft_c_lstsize(&head));

	// ft_printf("---------------------\n");
	// print_lst(head);
	// ft_printf("---------------------\n");
	// puts("iterated lst is:");
	// ft_c_lstiter(head, add2);
	// print_lst(head);
	// ft_printf("---------------------\n");
	// puts("iterated lst is:");
	// ft_c_lstiter(head, add2);
	// print_lst(head);

}
