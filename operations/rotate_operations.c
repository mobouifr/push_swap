/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:02:26 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:19 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **head)
{
	t_list	*tmp;

	if (!head)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head) = (*head)->next;
	tmp->next->next = NULL;
	update_index(head);
}

void	ft_ra(t_list **head_a)
{
	rotate(head_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **head_b)
{
	rotate(head_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **head_b, t_list **head_a)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}
