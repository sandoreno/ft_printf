/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:05:39 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/10 19:49:47 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	ch = (unsigned char)c;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (n--)
	{
		*(d + i) = *(s + i);
		if (*(s + i) == ch)
		{
			return (d + i + 1);
		}
		i++;
	}
	return (NULL);
}
