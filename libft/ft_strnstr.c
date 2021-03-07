/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:57:33 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/22 18:23:17 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ned, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(ned) == 0)
		return ((char*)hs);
	while (n != i && *(hs + i) != '\0')
	{
		if (*(hs + i) == *(ned + j))
		{
			while (*(ned + j) == *(hs + i + j)
					&& *(ned + j) != '\0'
					&& *(hs + i + j) != '\0' && n != i + j)
			{
				j++;
				if (*(ned + j) == '\0')
					return ((char*)hs + i);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
