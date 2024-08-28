/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:13:14 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/26 15:15:43 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	string_isempty(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0' && (argv[j][i] == ' ' || argv[j][i] == '	'
					|| argv[j][i] == '\n'))
		{
			if (argv[j][i] == '	')
				return (1);
			i++;
		}
		if (argv[j][i] == '\0')
			return (1);
		j++;
	}
	return (0);
}

void	check_doubles(int num_count, long *all_nums)
{
	int	j;
	int	i;

	j = 0;
	while (j < num_count)
	{
		i = j + 1;
		while (i < num_count)
		{
			if (all_nums[j] == all_nums[i])
			{
				write(2, "Error\n", 6);
				free(all_nums);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

int	count_input_numbers(int argc, char *argv[])
{
	int		j;
	int		k;
	int		num_count;
	char	**str;

	j = 1;
	num_count = 0;
	while (j < argc)
	{
		str = ft_split(argv[j], ' ');
		k = 0;
		while (str[k] != NULL)
		{
			num_count++;
			k++;
		}
		ft_free(str);
		j++;
	}
	return (num_count);
}

void	pars_checks(int argc, char **argv, long *all_nums)
{
	int		j;
	int		i;
	int		k;
	long	num;
	char	**str;

	j = 1;
	i = 0;
	while (j < argc)
	{
		k = 0;
		str = ft_split(argv[j], ' ');
		while (str[k] != NULL)
		{
			num = ft_atoi(str[k], str, all_nums);
			all_nums[i++] = num;
			k++;
		}
		ft_free(str);
		j++;
	}
}
