/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_positioning_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:22:14 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/26 14:53:31 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	both_above(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		ft_rr(stack_a, stack_b);
	while (*stack_b != cheapest_node->target)
		ft_rb(stack_b);
	while (*stack_a != cheapest_node)
		ft_ra(stack_a);
}

static void	both_bellow(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		ft_rrr(stack_a, stack_b);
	while (*stack_b != cheapest_node->target)
		ft_rrb(stack_b);
	while (*stack_a != cheapest_node)
		ft_rra(stack_a);
}

static void	only_node_above(int node_abovemed, t_list **stack_a,
		t_list *cheapest_node)
{
	if (node_abovemed)
		while (*stack_a != cheapest_node)
			ft_ra(stack_a);
	else
		while (*stack_a != cheapest_node)
			ft_rra(stack_a);
}

static void	only_target_above(int target_abovemed, t_list **stack_b,
		t_list *cheapest_node)
{
	if (target_abovemed)
		while (*stack_b != cheapest_node->target)
			ft_rb(stack_b);
	else
		while (*stack_b != cheapest_node->target)
			ft_rrb(stack_b);
}

void	node_positioning_a(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	int	node_abovemed;
	int	target_abovemed;

	node_abovemed = is_above_med(*stack_a, cheapest_node);
	target_abovemed = is_above_med(*stack_b, cheapest_node->target);
	if (node_abovemed && target_abovemed)
		both_above(stack_a, stack_b, cheapest_node);
	else if (!node_abovemed && !target_abovemed)
		both_bellow(stack_a, stack_b, cheapest_node);
	else
	{
		only_node_above(node_abovemed, stack_a, cheapest_node);
		only_target_above(target_abovemed, stack_b, cheapest_node);
	}
}
