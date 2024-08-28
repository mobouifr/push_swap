/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:50:10 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/20 22:10:01 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->content = content;
	new->index = index;
	new->price = 0;
	new->next = NULL;
	new->target = NULL;
	return (new);
}
