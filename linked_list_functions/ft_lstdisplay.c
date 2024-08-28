/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:18:39 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/21 18:23:28 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdisplay(t_list *stack)
{
	while (stack != NULL)
	{
		stack = stack->next;
	}
}
// printf("node : %d\n",stack->content);
// put this line above inside the while in case of use.
