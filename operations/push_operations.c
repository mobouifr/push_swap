/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:02:19 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:11 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (head_b == NULL)
		return ;
	tmp = *head_b;
	*head_b = tmp->next;
	if (*head_a == NULL)
	{
		*head_a = tmp;
		(*head_a)->next = NULL;
	}
	else
	{
		tmp->next = *head_a;
		*head_a = tmp;
	}
	update_index(head_a);
	update_index(head_b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (head_a == NULL)
		return ;
	tmp = *head_a;
	*head_a = tmp->next;
	if (*head_b == NULL)
	{
		*head_b = tmp;
		(*head_b)->next = NULL;
	}
	else
	{
		tmp->next = *head_b;
		*head_b = tmp;
	}
	update_index(head_a);
	update_index(head_b);
	write(1, "pb\n", 3);
}
