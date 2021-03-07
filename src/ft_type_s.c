/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:13:52 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:18 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_str(char *s, int len)
{
	int i;

	i = 0;
	while (i != len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

int		ft_print_wi_zer_str(int len, char c)
{
	int i;

	i = 0;
	while (len != 0)
	{
		ft_putchar_fd(c, 1);
		len = len - 1;
		i = i + 1;
	}
	return (i);
}

int		checking_conditions_str(char *s, int w_len, int pr_len, t_pt *list)
{
	int i;

	i = 0;
	if (list->minus == 1)
	{
		w_len = w_len - pr_len;
		i = ft_print_str(s, pr_len);
		i += ft_print_wi_zer_str(w_len, ' ');
	}
	else if (list->zero == 1)
	{
		w_len = w_len - pr_len;
		i = ft_print_wi_zer_str(w_len, '0');
		i += ft_print_str(s, pr_len);
	}
	else
	{
		w_len = w_len - pr_len;
		i = ft_print_wi_zer_str(w_len, ' ');
		i += ft_print_str(s, pr_len);
	}
	return (i);
}

int		ft_write_s(char *s, int pr_len, t_pt *list)
{
	int i;
	int w_len;

	i = 0;
	w_len = list->width;
	if (w_len > pr_len)
		i = checking_conditions_str(s, w_len, pr_len, list);
	else
		i = ft_print_str(s, pr_len);
	return (i);
}

int		ft_type_s(va_list *a, t_pt *list)
{
	int		i;
	int		len;
	int		prlen;
	char	*s;

	i = 0;
	s = va_arg(*a, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (list->precision < 0)
		list->precision = -1;
	if (len > list->precision && list->precision != -1)
		prlen = list->precision;
	else
		prlen = len;
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = list->width * -1;
	}
	i = ft_write_s(s, prlen, list);
	return (i);
}
