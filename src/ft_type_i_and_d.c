/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i_and_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 01:23:28 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:08 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_pr_len(char *s, int pr_len, int d, t_pt *list)
{
	int i;
	int len;

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
			i = ft_print_zero(d, pr_len, s);
	}
	else
	{
		if (list->precision == len && d < 0)
			i = ft_print_zero(d, pr_len, s);
		else
			i = ft_print_str(s, pr_len);
	}
	return (i);
}

int		ft_print_w_len(char *s, int w_len, int d, t_pt *list)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (w_len > len)
	{
		if (d >= 0)
			i = checking_conditions_str(s, w_len, len, list);
		else if (d < 0)
		{
			if (list->zero == 1 && list->minus != 1)
				i = ft_print_zero1(d, w_len, s);
			else
				i = checking_conditions_str(s, w_len, len, list);
		}
	}
	else
		i = ft_print_str(s, len);
	return (i);
}

int		ft_write_d(char *s, int pr_len, t_pt *list, int d)
{
	int i;
	int w_len;

	i = 0;
	w_len = list->width;
	if (list->precision == 0 && d == 0)
	{
		if (list->width != 0)
			i = ft_print_wi_zer_str(list->width, ' ');
	}
	else
	{
		if (w_len == 0 && pr_len != -1)
			i = ft_print_pr_len(s, pr_len, d, list);
		else if (w_len != 0 && pr_len == -1)
			i = ft_print_w_len(s, w_len, d, list);
		else if (w_len != 0 && pr_len != -1)
			i = func_parsing_five(list, w_len, pr_len, d);
		else if (w_len == 0 && pr_len == -1)
		{
			pr_len = ft_strlen(s);
			i = ft_print_str(s, pr_len);
		}
	}
	return (i);
}

int		ft_type_i_and_d(va_list *a, t_pt *list)
{
	int		i;
	int		d;
	int		len;
	int		prlen;
	char	*s;

	i = 0;
	d = va_arg(*a, int);
	if (list->precision < 0)
		list->precision = -1;
	s = (char *)ft_itoa(d);
	len = ft_strlen(s);
	if (len > list->precision && list->precision != -1)
		prlen = len;
	else
		prlen = list->precision;
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = list->width * -1;
	}
	i = ft_write_d(s, prlen, list, d);
	free(s);
	return (i);
}
