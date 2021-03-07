/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:20:18 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/17 20:31:13 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t num;
	size_t copy;
	size_t step;

	step = 1;
	num = (size_t)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = (size_t)n * -1;
	}
	copy = num;
	while ((num /= 10) >= 1)
		step *= 10;
	while (step > 0)
	{
		num = copy / step + '0';
		copy = copy % step;
		step /= 10;
		write(fd, &num, 1);
	}
}
