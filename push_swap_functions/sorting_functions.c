/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:18:41 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/25 16:12:30 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	not_sorted(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		ft_sa(stack_a);
	}
}

void	sort_three(t_list **stack_a)
{
	t_list	*max;

	max = ft_lstmax(*stack_a);
	if ((*stack_a)->content == max->content)
		ft_ra(stack_a);
	else if ((*stack_a)->next->content == max->content)
		ft_rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	if (ft_lstsize(*stack_a) > 4)
		ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{
		get_nodesprices_a(stack_a, stack_b);
		cheapest_node = get_lowestprice(*stack_a);
		node_positioning_a(stack_a, stack_b, cheapest_node);
		ft_pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		get_nodesprices_b(stack_a, stack_b);
		cheapest_node = get_lowestprice(*stack_b);
		node_positioning_b(stack_a, stack_b, cheapest_node);
		ft_pa(stack_a, stack_b);
	}
	check_lowestnum(stack_a);
}
