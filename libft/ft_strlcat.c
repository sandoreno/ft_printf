/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:45:45 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/22 19:00:23 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t size_dst;
	size_t size_src;

	i = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	j = size_dst;
	if (dstsize > 0 && dstsize > size_dst)
	{
		while (*(src + i) != '\0' && i < dstsize - 1 - size_dst)
		{
			*(dst + j) = *(src + i);
			i++;
			j++;
		}
		*(dst + j) = '\0';
		return (size_dst + size_src);
	}
	return (dstsize + size_src);
}
