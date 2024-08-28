/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:53:33 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/27 12:49:18 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_target_a(t_list *stack_b, t_list *node)
{
	t_list	*target;
	t_list	*tmp;
	long	closest_targ;

	closest_targ = LONG_MIN;
	tmp = stack_b;
	while (stack_b != NULL)
	{
		if (stack_b->content > closest_targ && stack_b->content < node->content)
		{
			closest_targ = stack_b->content;
			target = stack_b;
		}
		stack_b = stack_b->next;
	}
	stack_b = tmp;
	if (closest_targ == LONG_MIN)
		target = ft_lstmax(stack_b);
	return (target);
}

t_list	*find_target_b(t_list *stack_a, t_list *node)
{
	t_list	*target;
	long	closest_targ;
	t_list	*tmp;

	closest_targ = LONG_MAX;
	tmp = stack_a;
	while (stack_a != NULL)
	{
		if (stack_a->content < closest_targ && stack_a->content > node->content)
		{
			closest_targ = stack_a->content;
			target = stack_a;
		}
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	if (closest_targ == LONG_MAX)
		target = ft_lstmin(stack_a);
	return (target);
}
