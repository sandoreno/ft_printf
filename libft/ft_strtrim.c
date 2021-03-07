/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:30:52 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/25 20:21:12 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_has_occurence(char s1, char const *set)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (*(set + i) != '\0')
	{
		if (s1 == *(set + i))
			count++;
		i++;
	}
	if (count > 0)
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i1;
	size_t	i2;
	size_t	i;
	char	*memory;

	if (s1 == NULL)
		return (NULL);
	if (ft_strlen(s1) != 0)
		i2 = ft_strlen(s1) - 1;
	else
		i2 = 0;
	i1 = 0;
	while (ft_has_occurence(*(s1 + i1), set))
		i1++;
	while (ft_has_occurence(*(s1 + i2), set) && i1 <= i2)
		i2--;
	if (!(memory = malloc(((i2 - i1) + 2) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i1 <= i2)
		*(memory + i++) = *(s1 + i1++);
	*(memory + i) = '\0';
	return (memory);
}
