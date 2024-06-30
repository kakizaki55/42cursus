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
// # define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

//push_swap_utils.c
t_c_list	*ft_c_lstnew(int content);
void 		ft_c_push(t_c_list **src, t_c_list **dest, char stack);
void		ft_c_lstadd(t_c_list **head, t_c_list *new);
t_c_list 	*ft_lstpop(t_c_list **head);
int			ft_c_lstsize(t_c_list *lst);
void 		ft_c_print_lst(t_c_list *head, char stack);
void 		ft_rotate(t_c_list **head, char stack);
void		ft_r_rotate(t_c_list **head, char stack);
void		rotate_stack(t_c_list **src, int stack, int index);
void		ft_lstswap(t_c_list **head, char stack);
void 		ft_c_lstclear(t_c_list **head);

//args_validation.c
int *args_validation(int argc, char *argv[]);
int print_arr(int *arr, int len);

//compress.c
int *compress(int *arr, int len);
int is_smaller(int a, int b);
int is_bigger(int a, int b);
int find_min_index(int *arr, int len);

//sort_utils.c
int check_sort(t_c_list *head);
int check_r_sort(t_c_list *head);
int find_nbr(t_c_list *head, int nbr);
int find_r_nbr(t_c_list *head, int nbr);
int check_any_sort(t_c_list *head);
int check_any_r_sort(t_c_list *head);
int find_min(t_c_list *head);
int find_max(t_c_list *head);
int recon_smaller(t_c_list *head, int deli);
int recon_larger(t_c_list *head, int deli);
void push_all(t_c_list **src_lst, t_c_list **dest_lst, char dest_stack);
void push_all_large(t_c_list **src_lst, t_c_list **dest_lst, char dest_stack);
// void rotate_to_target(t_c_list **head, int target_nbr, char stack);

//short_sort.c
void split_lsts(t_c_list **stack_a, t_c_list **stack_b, int half);
int sort_two(t_c_list **head, char stack);
int sort_three(t_c_list **head,int target_nbr, char stack);
int sort_two_three(t_c_list **head, int len, char stack);
int sort_six(t_c_list **stack_a, t_c_list **stack_b, int len);
int sort_short(t_c_list **stack_a, t_c_list **stack_b, int len);

//sort.c
void sort(t_c_list **head, int len);



#endif