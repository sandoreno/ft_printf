/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:56:46 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:01 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent(t_pt *list, int i)
{
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = list->width * -1;
	}
	if (list->minus == 1 && list->width != 0)
	{
		ft_putchar_fd('%', 1);
		i += ft_print_wi_zer_str(list->width - 1, ' ');
	}
	else if (list->zero != 0 && list->width != 0)
	{
		i += ft_print_wi_zer_str(list->width - 1, '0');
		ft_putchar_fd('%', 1);
	}
	else if (list->minus != 1 && list->width != 0)
	{
		i += ft_print_wi_zer_str(list->width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	else
		ft_putchar_fd('%', 1);
	return (i);
}

int		ft_type_c(va_list *a, t_pt *list)
{
	int		i;
	char	c;

	c = (char)va_arg(*a, int);
	i = 1;
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = list->width * -1;
	}
	if ((list->minus == 1 || list->zero == 1) && list->width != 0)
	{
		ft_putchar_fd(c, 1);
		i += ft_print_wi_zer_str(list->width - 1, ' ');
	}
	else if (list->minus != 1 && list->width != 0)
	{
		i += ft_print_wi_zer_str(list->width - 1, ' ');
		ft_putchar_fd(c, 1);
	}
	else
		ft_putchar_fd(c, 1);
	return (i);
}

int		ft_print_zero(int d, int len, char *s)
{
	int i;

	i = 1;
	d *= -1;
	s = ft_itoa(d);
	len = len - ft_strlen(s);
	ft_putchar_fd('-', 1);
	i += ft_print_wi_zer_str(len, '0');
	i += ft_print_str(s, ft_strlen(s));
	free(s);
	return (i);
}

int		ft_print_zero1(int d, int len, char *s)
{
	int i;

	i = 1;
	len = len - ft_strlen(s);
	d *= -1;
	s = ft_itoa(d);
	ft_putchar_fd('-', 1);
	i += ft_print_wi_zer_str(len, '0');
	i += ft_print_str(s, ft_strlen(s));
	free(s);
	return (i);
}
