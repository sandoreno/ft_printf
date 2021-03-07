/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:21:00 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/22 19:19:26 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	size_t	s1_len;
	char	*memory;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	memory = malloc(len + 1 * sizeof(char));
	if (memory == NULL)
		return (NULL);
	while (i != s1_len)
	{
		*(memory + i) = *s1++;
		i++;
	}
	while (i != len)
	{
		*(memory + i) = *s2++;
		i++;
	}
	*(memory + len) = '\0';
	return (memory);
}
