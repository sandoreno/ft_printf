/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:56:20 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/27 16:41:56 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_word(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static	char	**ft_malloc_word(char **arr, size_t i, size_t j)
{
	if (!(arr[i] = malloc((j + 1) * sizeof(char))))
	{
		while (i--)
			free(arr[i]);
		free(arr);
		return (NULL);
	}
	return (arr);
}

static	char	**ft_memmory_allocation(size_t count, const char *s,
				char c, char **arr)
{
	size_t arr_i;
	size_t arr_j;
	size_t i;

	arr_i = 0;
	arr_j = 0;
	i = 0;
	while (arr_i < count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + arr_j] != c && s[i + arr_j] != '\0')
			arr_j++;
		if (!(ft_malloc_word(arr, arr_i, arr_j)))
			return (NULL);
		arr_i++;
		i += arr_j;
		arr_j = 0;
	}
	return (arr);
}

static	char	**ft_fill_memmory(size_t count, const char *s, char c,
				char **arr)
{
	size_t arr_i;
	size_t arr_j;
	size_t i;

	arr_i = 0;
	arr_j = 0;
	i = 0;
	while (arr_i < count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + arr_j] != c && s[i + arr_j] != '\0')
		{
			arr[arr_i][arr_j] = s[i + arr_j];
			arr_j++;
		}
		arr[arr_i][arr_j] = '\0';
		arr_i++;
		i += arr_j;
		arr_j = 0;
	}
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	size_t	count;
	char	**arr;

	if (s == NULL)
		return (NULL);
	count = ft_count_word(s, c);
	if (!(arr = malloc((count + 1) * sizeof(char*))))
		return (NULL);
	if (!(ft_memmory_allocation(count, s, c, arr)))
		return (NULL);
	ft_fill_memmory(count, s, c, arr);
	arr[count] = NULL;
	return (arr);
}
