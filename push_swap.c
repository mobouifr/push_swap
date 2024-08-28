/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:02:08 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/21 18:19:27 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int num_count, long *all_nums)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	fill_stack_a(&stack_a, all_nums, num_count);
	if (not_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			sort_two(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_all(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char *argv[])
{
	int		num_count;
	long	*all_nums;

	all_nums = NULL;
	if (argc < 2)
		return (0);
	if (string_isempty(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	num_count = count_input_numbers(argc, argv);
	all_nums = (long *)malloc(sizeof(long) * num_count);
	if (all_nums == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	pars_checks(argc, argv, all_nums);
	check_doubles(num_count, all_nums);
	sort(num_count, all_nums);
	free(all_nums);
	return (0);
}
