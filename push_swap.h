/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:05:29 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/21 17:19:29 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				price;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

//.....PARSE FUNCTIONS.....//
void				ft_free(char **str);
void				check_doubles(int count, long *nums);
int					count_input_numbers(int argc, char *argv[]);
void				pars_checks(int argc, char **argv, long *all_nums);
int					string_isempty(int argc, char **argv);

/////////////////////////..OPEARATIONS..///////////////////////////
//.....SWAP OPERATIONS.....//
void				swap(t_list **head);
void				ft_sa(t_list **head_a);
void				ft_sb(t_list **head_b);
void				ft_ss(t_list **head_a, t_list **head_b);
//.....PUSH OPERATIONS.....//
void				ft_pa(t_list **head_a, t_list **head_b);
void				ft_pb(t_list **head_a, t_list **head_b);
//.....ROTATE OPERATIONS.....//
void				rotate(t_list **head);
void				ft_ra(t_list **head_a);
void				ft_rb(t_list **head_b);
void				ft_rr(t_list **head_b, t_list **head_a);
//.....REVERSE ROTATE OPERATIONS.....//
void				reverse_rotate(t_list **head);
void				ft_rra(t_list **head_a);
void				ft_rrb(t_list **head_b);
void				ft_rrr(t_list **head_a, t_list **head_b);
//////////////////////////////////////////////////////////////////

////////////////////..LINKED LIST FUNCTIONS../////////////////////
t_list				*ft_lstnew(int content, int index);
t_list				*ft_lstmax(t_list *stack_a);
t_list				*ft_lstmin(t_list *stack_a);
void				ft_lstaddfront(t_list **lst, t_list *new);
void				ft_lstaddfront(t_list **lst, t_list *new);
void				ft_lstaddback(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstdisplay(t_list *stack);
void				ft_lstclear(t_list **lst);
/////////////////////////////////////////////////////////////////

/////////////////////..PUSH_SWAP_FUNCTIONS../////////////////////
void				check_lowestnum(t_list **stack_a);
void				update_index(t_list **stack);
void				fill_stack_a(t_list **stack_a, long *all_nums,
						int num_count);
void				find_price(t_list *stack_a, t_list *stack_b, t_list **node);
void				node_positioning_a(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node);
void				node_positioning_b(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node);
//.....FIND PRICE EXTN.....//
void				get_nodesprices_a(t_list **stack_a, t_list **stack_b);
void				get_nodesprices_b(t_list **stack_a, t_list **stack_b);
t_list				*get_lowestprice(t_list *stack);
int					is_above_med(t_list *stack, t_list *node);
//.....FIND_TARGET.....//
t_list				*find_target_a(t_list *stack_b, t_list *node);
t_list				*find_target_b(t_list *stack_a, t_list *node);
//.....SORTING_FUNCTIONS.....//
void				sort_two(t_list **stack_a);
void				sort_three(t_list **stack_a);
void				sort_all(t_list **stack_a, t_list **stack_b);
int					not_sorted(t_list *stack_a);
////////////////////////////////////////////////////////////////

///////////..STILL_NOT_ADRESSED../////////////
void				update_index(t_list **stack);

#endif
