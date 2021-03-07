/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:35:01 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/10 19:53:16 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (s >= d)
	{
		while (len--)
			*(d++) = *(s++);
	}
	else
	{
		i = len - 1;
		while (len--)
		{
			*(d + i) = *(s + i);
			i--;
		}
	}
	return (dst);
}
