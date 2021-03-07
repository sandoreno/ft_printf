/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:40:45 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/10 22:25:16 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	i = 0;
	while (n != i && (*(s + i) != '\0' || *(d + i) != '\0'))
	{
		if (*(s + i) != *(d + i))
		{
			return (*(s + i) - *(d + i));
		}
		i++;
	}
	return (0);
}
