/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:11:37 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 20:56:23 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*memory;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(memory = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (len > i && *(s + start + i) != '\0')
		{
			*(memory + i) = *(s + start + i);
			i++;
		}
	}
	*(memory + i) = '\0';
	return (memory);
}
