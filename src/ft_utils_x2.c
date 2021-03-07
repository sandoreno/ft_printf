/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_x2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:33:47 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:57 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_zero_x(size_t x, int len, char *s, t_pt *list)
{
	int i;

	i = 1;
	x *= -1;
	s = conver_to_x(x, list);
	len = len - ft_strlen(s);
	ft_putchar_fd('-', 1);
	i += ft_print_wi_zer_str(len, '0');
	i += ft_print_str(s, ft_strlen(s));
	return (i);
}

int		ft_print_zero1_x(size_t x, int len, char *s, t_pt *list)
{
	int i;

	i = 1;
	len = len - ft_strlen(s);
	x *= -1;
	s = conver_to_x(x, list);
	ft_putchar_fd('-', 1);
	i += ft_print_wi_zer_str(len, '0');
	i += ft_print_str(s, ft_strlen(s));
	return (i);
}

int		ft_print_pr_len_x(char *s, int pr_len, size_t x, t_pt *list)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (pr_len > len)
	{
		if (x >= 0)
		{
			pr_len = pr_len - len;
			i = ft_print_wi_zer_str(pr_len, '0');
			i += ft_print_str(s, len);
		}
		else
			i = ft_print_zero_x(x, pr_len, s, list);
	}
	else
	{
		if (list->precision == len && x < 0)
			i = ft_print_zero_x(x, pr_len, s, list);
		else
			i = ft_print_str(s, pr_len);
	}
	return (i);
}

int		ft_print_w_len_x(char *s, int w_len, size_t x, t_pt *list)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (w_len > len)
	{
		if (x >= 0)
			i = checking_conditions_str(s, w_len, len, list);
		else if (x < 0)
		{
			if (list->zero == 1 && list->minus != 1)
				i = ft_print_zero1_x(x, w_len, s, list);
			else
				i = checking_conditions_str(s, w_len, len, list);
		}
	}
	else
		i = ft_print_str(s, len);
	return (i);
}
