/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:42:09 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/21 11:56:01 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	both_above(t_list **node)
{
	if ((*node)->index > (*node)->target->index)
		(*node)->price = (*node)->index;
	else
		(*node)->price = (*node)->target->index;
}

static void	both_bellow(int size_a, int size_b, t_list **node)
{
	if ((size_a - (*node)->index) > (size_b - (*node)->target->index))
		(*node)->price = size_a - (*node)->index;
	else
		(*node)->price = size_b - (*node)->target->index;
}

static void	only_node_above(int node_abovemed, int size_a, t_list **node)
{
	if (node_abovemed)
		(*node)->price = (*node)->index;
	else
		(*node)->price = size_a - (*node)->index;
}

static void	only_target_above(int target_abovemed, int size_b, t_list **node)
{
	if (target_abovemed)
		(*node)->price += (*node)->target->index;
	else
		(*node)->price += size_b - (*node)->target->index;
}

void	find_price(t_list *stack_a, t_list *stack_b, t_list **node)
{
	int	node_abovemed;
	int	target_abovemed;
	int	size_a;
	int	size_b;

	node_abovemed = is_above_med(stack_a, *node);
	target_abovemed = is_above_med(stack_b, (*node)->target);
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	if (node_abovemed && target_abovemed)
		both_above(node);
	else if (!node_abovemed && !target_abovemed)
		both_bellow(size_a, size_b, node);
	else
	{
		only_node_above(node_abovemed, size_a, node);
		only_target_above(target_abovemed, size_b, node);
	}
}
