/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lowestnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:59:41 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:25 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_lowestnum(t_list **stack_a)
{
	t_list	*min_node;
	int		is_above;

	min_node = ft_lstmin(*stack_a);
	is_above = is_above_med(*stack_a, min_node);
	while (*stack_a != min_node)
	{
		if (is_above == 1)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}
