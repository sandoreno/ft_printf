/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:42:32 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/19 13:15:07 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	while (*(str + i) != c && i != 0)
	{
		i--;
	}
	if (*(str + i) == c)
	{
		return ((char*)(str + i));
	}
	else
	{
		return (NULL);
	}
}
