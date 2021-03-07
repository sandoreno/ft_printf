/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:16:27 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/22 18:31:07 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			len;
	unsigned char	*mem;

	len = ft_strlen(s1) + 1;
	if (!(mem = malloc(len * sizeof(char))))
		return (NULL);
	mem = ft_memcpy(mem, s1, len);
	return ((char*)mem);
}
