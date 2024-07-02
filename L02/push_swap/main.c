/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/02 19:52:10 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// __attribute__((destructor))
// static void	destructor(void) {
// 	system ("leaks -q push_swap");
// }

t_c_list	*init(int *args_arr, int len)
{
	t_c_list	*a;
	int			i;

	a = NULL;
	i = len - 1 ;
	while (i >= 0)
	{
		ft_c_lstadd(&a, ft_c_lstnew(args_arr[i]));
		i--;
	}
	return (a);
}

int	main(int argc, char *argv[])
{	
	t_c_list	*head;
	int			*args_arr;
	int			len;

	if (argc <= 1)
		return (1);
	head = NULL;
	args_arr = args_validation(argc, argv);
	len = argc - 1;
	args_arr = compress(args_arr, len);
	head = init(args_arr, len);
	free(args_arr);
	sort(&head, len);
	return (0);
}
