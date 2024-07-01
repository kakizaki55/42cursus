/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/01 19:33:07 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

t_c_list *init(int *args_arr, int len)
{
	t_c_list *a;
	int i;
	a = NULL;

	i = len - 1 ;
	while(i >= 0)
	{
		ft_c_lstadd(&a, ft_c_lstnew(args_arr[i]));
		i--;
	}
	return (a);
}

int	main(int argc, char *argv[])
{	
	t_c_list *head;
	int *args_arr;
	int len;

	if(argc <= 1)
		return (1);
	head = NULL;
	args_arr = args_validation(argc, argv);
	len = argc - 1;         
	args_arr = compress(args_arr, len);

	head = init(args_arr, len);
	free(args_arr);
	sort(&head, len);

	// ft_c_lstclear(&head);

	// ft_c_print_lst(head, 'a');
	
	// ft_printf("1 is sorted 0 is not:%d\n", check_sorted(head));
	// ft_printf("3 is at index:%d\n", find_nbr(head, 3));
	// ft_printf("1 is sorted 0 is not:%d\n", check_r_sorted(head));


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
