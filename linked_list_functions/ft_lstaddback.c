/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:58:38 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:08:47 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstaddback(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
