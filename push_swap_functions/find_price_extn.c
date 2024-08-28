/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_price_extn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:05:44 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:35 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_nodesprices_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_node;

	tmp_node = *stack_a;
	while (tmp_node != NULL)
	{
		tmp_node->target = find_target_a(*stack_b, tmp_node);
		find_price(*stack_a, *stack_b, &tmp_node);
		tmp_node = tmp_node->next;
	}
}

void	get_nodesprices_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_node;

	tmp_node = *stack_b;
	while (tmp_node != NULL)
	{
		tmp_node->target = find_target_b(*stack_a, tmp_node);
		find_price(*stack_b, *stack_a, &tmp_node);
		tmp_node = tmp_node->next;
	}
}

int	is_above_med(t_list *stack, t_list *node)
{
	int	size;

	size = ft_lstsize(stack);
	if (node->index <= (size / 2))
		return (1);
	return (0);
}

t_list	*get_lowestprice(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack->next != NULL)
	{
		if (stack->next->price < min->price)
			min = stack->next;
		stack = stack->next;
	}
	return (min);
}
