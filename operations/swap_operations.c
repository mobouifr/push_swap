/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:02:29 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:22 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **head)
{
	t_list	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = (*head);
	*head = (*head)->next;
	tmp->next = tmp->next->next;
	(*head)->next = tmp;
	update_index(head);
}

void	ft_sa(t_list **head_a)
{
	swap(head_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **head_b)
{
	swap(head_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
	write(1, "ss\n", 3);
}
