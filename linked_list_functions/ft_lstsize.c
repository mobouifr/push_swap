/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:55:22 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:05 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (1);
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
