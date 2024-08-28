/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:50:39 by mobouifr          #+#    #+#             */
/*   Updated: 2024/08/26 15:06:40 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrdcount(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (count);
}

static size_t	wrdlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**ft_free(char **ptr, size_t j)
{
	while (j > 0)
	{
		free(ptr[j - 1]);
		j--;
	}
	free(ptr);
	return (NULL);
}

static char	*help(char const *s, char c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(wrdlen(s, c) + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((wrdcount(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			ptr[i] = help(s, c);
			if (ptr[i] == NULL)
				return (ft_free(ptr, i));
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}
/*
 int	main(void)
 {
	char const    *input_string;
	char        **result;
	int            i;

	input_string = "lkhdra";

	result = ft_split(input_string, NULL);
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	system("leaks a.out");
	return (0);
 }*/