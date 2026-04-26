/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:55:21 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/29 17:47:45 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack_a(t_list **stack_a, int *all_nums, int num_count)
{
	int	i;

	i = 0;
	while (i < num_count)
	{
		ft_lstaddback(stack_a, ft_lstnew(all_nums[i], i));
		i++;
	}
}
