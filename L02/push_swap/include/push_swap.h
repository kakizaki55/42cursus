/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:50 by mkakizak          #+#    #+#             */
/*   Updated: 2024/07/02 18:29:55 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct c_list
{
	int				content;
	struct c_list	*next;
	struct c_list	*prev;
}	t_c_list;

# define TRUE  1
# define FALSE 0

//push_swap_utils.c
t_c_list	*ft_c_lstnew(int content);
void		ft_c_push(t_c_list **src, t_c_list **dest, char stack);
void		ft_c_lstadd(t_c_list **head, t_c_list *new);
t_c_list	*ft_lstpop(t_c_list **head);
int			ft_c_lstsize(t_c_list *lst);
void		ft_c_print_lst(t_c_list *head, char stack);
void		ft_rotate(t_c_list **head, char stack);
void		ft_r_rotate(t_c_list **head, char stack);
void		rotate_stack(t_c_list **src, int stack, int index);
void		ft_lstswap(t_c_list **head, char stack);
void		ft_c_lstclear(t_c_list **head);

//args_validation.ccle
int			*args_validation(int argc, char *argv[]);
int			print_arr(int *arr, int len);
void		error(void);

//compress.c
int			*compress(int *arr, int len);
int			is_smaller(int a, int b);
int			is_bigger(int a, int b);
int			find_min_index(int *arr, int len);

//sort_utils.c
int			check_sort(t_c_list *head);
int			check_r_sort(t_c_list *head);
int			find_nbr(t_c_list *head, int nbr);
int			find_r_nbr(t_c_list *head, int nbr);
int			check_any_sort(t_c_list *head);
int			check_any_r_sort(t_c_list *head);
int			find_min(t_c_list *head);
int			find_max(t_c_list *head);
int			recon_smaller(t_c_list *head, int deli);
int			recon_larger(t_c_list *head, int deli);
void		push_all(t_c_list **src_lst, t_c_list **dest_lst, char dest_stack);
void		push_all_large(t_c_list **src, t_c_list **dest, char dest_stack);
void		split_lsts_tw_thr(t_c_list **stack_a, t_c_list **stack_b, int len);
int			check_sorted_two_three(t_c_list *head, char stack);
char		get_other_stack(char c);
void		splt_lst_hlf(t_c_list **src, t_c_list **dest, char stk, int dlmt);

//short_sort.c
int			sort_short(t_c_list **stack_a, t_c_list **stack_b, int len);

//sort.c
void		sort(t_c_list **head, int len);
int			find_sortest_path(t_c_list **src, int target_nbr);

//ft_atoi_long.c
long		ft_atoi_long(const char *str);
#endif