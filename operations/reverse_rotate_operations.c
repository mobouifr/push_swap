/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:02:22 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:16 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->next->next == NULL)
		{
			last = tmp;
		}
		tmp = tmp->next;
	}
	tmp->next = *head;
	*head = tmp;
	last->next = NULL;
	update_index(head);
}

void	ft_rra(t_list **head_a)
{
	reverse_rotate(head_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **head_b)
{
	reverse_rotate(head_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **head_a, t_list **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	write(1, "rrr\n", 4);
}
