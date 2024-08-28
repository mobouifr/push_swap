/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:01:44 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/21 11:50:46 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
