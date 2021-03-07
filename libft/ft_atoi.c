/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:16:59 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/22 19:03:34 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\t' || *(str + i) == '\v' || *(str + i) == '\n' ||
	*(str + i) == '\f' || *(str + i) == ' ' || *(str + i) == '\r')
		i++;
	if (*(str + i) == '+')
		i++;
	else if (*(str + i) == '-')
	{
		sign = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + *(str + i) - '0';
		i++;
	}
	if (num * sign < -2147483648 || num * sign > 2147483648)
		return (sign == 1 ? -1 : 0);
	return (num * sign);
}
