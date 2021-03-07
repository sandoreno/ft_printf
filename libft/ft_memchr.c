/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:32:41 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/08 22:02:22 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*(str + i) == ch)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
