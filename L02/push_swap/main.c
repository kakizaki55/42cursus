/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:32 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/09 21:39:09 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include "pushswap.h"

int	main(int argc, char *argv[])
{

	t_c_list *head;
	int num1 = 1;
	int num2 = 2;
	head = ft_c_lstnew(num1);
	ft_c_lstadd(&head, ft_c_lstnew(num2));
	ft_c_lstadd(&head, ft_c_lstnew(3));
	ft_c_lstadd(&head, ft_c_lstnew(4));

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
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
