/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:52:14 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:09:11 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstaddfront(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	(*lst) = new;
	(*lst)->next = tmp;
}
