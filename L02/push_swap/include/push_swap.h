/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:50 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/14 12:01:04 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct c_list
{
	int				content;
	struct c_list	*next;
	struct c_list	*prev;
	int 			head;
}	t_c_list;

# define true  1
# define false 0

// # define true = 1
// # define false = 0

// extern int *ARGS = "1 2 3 4 5 6";

t_c_list	*ft_c_lstnew(int content);
int			ft_c_lstsize(t_c_list **lst);
void		ft_c_lstadd(t_c_list **head, t_c_list *new);
void 		ft_c_print_lst(t_c_list *head);
void 		rotate(t_c_list **head);
void		r_rotate(t_c_list **head);
t_c_list 	*ft_lstpop(t_c_list **head);
void		ft_lstswap(t_c_list **head);
void		ft_c_lstiter(t_c_list *head, int (*f)(int));
void 		ft_c_lstclear(t_c_list **head);
int 		add2(int number);

int *args_validation(int argc, char *argv[]);
int print_arr(int *arr);



#endif