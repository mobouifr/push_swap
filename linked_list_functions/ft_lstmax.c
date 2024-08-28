/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:14:44 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:09:52 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstmax(t_list *stack_a)
{
	t_list	*max;

	max = stack_a;
	while (stack_a->next != NULL)
	{
		if (stack_a->next->content > max->content)
			max = stack_a->next;
		stack_a = stack_a->next;
	}
	return (max);
}
