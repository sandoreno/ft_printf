/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:40:44 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 20:40:28 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		intlen(int n)
{
	size_t len;
	size_t num;

	len = 0;
	num = (size_t)n;
	if (n <= 0)
	{
		len = 1;
		num = (size_t)n * -1;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static	char	*array_fi(size_t num, size_t step, size_t i, char *arr)
{
	size_t copy;

	copy = num;
	while ((num /= 10) >= 1)
		step *= 10;
	while (step > 0)
	{
		*(arr + i++) = copy / step + '0';
		copy = copy % step;
		step /= 10;
	}
	*(arr + i) = '\0';
	return (arr);
}

char			*ft_itoa(int n)
{
	size_t		num;
	size_t		step;
	size_t		i;
	char		*arr;

	step = 1;
	i = 0;
	if (!(arr = malloc((intlen(n) + 1) * sizeof(char))))
		return (NULL);
	num = (size_t)n;
	if (n < 0)
	{
		*(arr + i++) = '-';
		num = (size_t)n * -1;
	}
	array_fi(num, step, i, arr);
	return (arr);
}
