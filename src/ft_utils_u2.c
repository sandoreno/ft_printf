/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_u2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:33:39 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:47 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_zero_u(size_t d, int len, char *s)
{
	int	i;

	i = 1;
	d *= -1;
	s = ft_itoa_u(d);
	len = len - ft_strlen(s);
	ft_putchar_fd('-', 1);
	i += ft_print_wi_zer_str(len, '0');
	i += ft_print_str(s, ft_strlen(s));
	return (i);
}

int		ft_print_zero1_u(size_t d, int len, char *s)
{
	int	i;

	i = 1;
	len = len - ft_strlen(s);
	d *= -1;
	s = ft_itoa_u(d);
	ft_putchar_fd('-', 1);
	i += ft_print_wi_zer_str(len, '0');
	i += ft_print_str(s, ft_strlen(s));
	return (i);
}

int		ft_print_pr_len_u(char *s, int pr_len, size_t d, t_pt *list)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (pr_len > len)
	{
		if (d >= 0)
		{
			pr_len = pr_len - len;
			i = ft_print_wi_zer_str(pr_len, '0');
			i += ft_print_str(s, len);
		}
		else
			i = ft_print_zero_u(d, pr_len, s);
	}
	else
	{
		if (list->precision == len && d < 0)
			i = ft_print_zero_u(d, pr_len, s);
		else
			i = ft_print_str(s, pr_len);
	}
	return (i);
}

int		ft_print_w_len_u(char *s, int w_len, size_t d, t_pt *list)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (w_len > len)
	{
		if (d >= 0)
			i = checking_conditions_str(s, w_len, len, list);
		else if (d < 0)
		{
			if (list->zero == 1 && list->minus != 1)
				i = ft_print_zero1_u(d, w_len, s);
			else
				i = checking_conditions_str(s, w_len, len, list);
		}
	}
	else
		i = ft_print_str(s, len);
	return (i);
}
