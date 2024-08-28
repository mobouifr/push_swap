/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:57:59 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:12:02 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_index(t_list **stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}
