/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:58:05 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/08 21:07:08 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (n != i)
	{
		if (*(s + i) != *(d + i))
		{
			return (*(s + i) - *(d + i));
		}
		i++;
	}
	return (0);
}
