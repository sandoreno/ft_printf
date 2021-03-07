/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:15:20 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:29 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_x(char *s, int pr_len, t_pt *list, size_t x)
{
	int i;
	int w_len;

	i = 0;
	w_len = list->width;
	if (list->precision == 0 && x == 0)
	{
		if (list->width != 0)
			i = ft_print_wi_zer_str(list->width, ' ');
	}
	else
	{
		if (w_len == 0 && pr_len != -1)
			i = ft_print_pr_len_x(s, pr_len, x, list);
		else if (w_len != 0 && pr_len == -1)
			i = ft_print_w_len_x(s, w_len, x, list);
		else if (w_len != 0 && pr_len != -1)
			i = func_parsing_five_x(list, w_len, pr_len, x);
		else if (w_len == 0 && pr_len == -1)
		{
			pr_len = ft_strlen(s);
			i = ft_print_str(s, pr_len);
		}
	}
	return (i);
}

int		ft_strl(size_t x)
{
	int i;

	i = 0;
	while (x != 0)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

char	*conver_to_x(size_t x, t_pt *list)
{
	int		ost;
	int		len;
	char	*a;

	len = ft_strl(x);
	if (!(a = malloc(sizeof(char *) * len)))
	{
		free(a);
		return (NULL);
	}
	a[len] = '\0';
	while (x != 0)
	{
		len = len - 1;
		ost = x % 16;
		if (ost > 9)
			if (list->type == 120)
				*(a + len) = (char)('a' - 10 + ost);
			else
				*(a + len) = (char)('A' - 10 + ost);
		else
			*(a + len) = (char)('0' + ost);
		x = x / 16;
	}
	return (a);
}

int		ft_type_x(va_list *a, t_pt *list)
{
	int			i;
	size_t		x;
	int			len;
	char		*s;

	i = 0;
	x = va_arg(*a, unsigned int);
	if (list->precision < 0)
		list->precision = -1;
	if (x != 0)
		s = conver_to_x(x, list);
	else
		s = (char *)ft_itoa_u(x);
	len = ft_strl(x);
	if (len < list->precision || list->precision == -1)
		len = list->precision;
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = list->width * -1;
	}
	i = ft_write_x(s, len, list, x);
	free(s);
	return (i);
}
