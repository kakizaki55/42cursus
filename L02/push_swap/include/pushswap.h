/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:50 by mkakizak          #+#    #+#             */
/*   Updated: 2024/06/12 23:25:11 by mkakizak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct c_list
{
	int				content;
	struct c_list	*next;
	struct c_list	*prev;
	int 			head;
}	t_c_list;

t_c_list	*ft_c_lstnew(int content);
int			ft_c_lstsize(t_c_list **lst);
void		**ft_c_lstadd(t_c_list **head, t_c_list *new);
void 		print_lst(t_c_list *head);
void 		rotate(t_c_list **head);
void		r_rotate(t_c_list **head);
t_c_list 	*ft_lstpop(t_c_list **head);
void		ft_lstswap(t_c_list **head);




#endif