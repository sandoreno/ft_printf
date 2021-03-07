/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 07:10:11 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:13 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conver_to_p(size_t p)
{
	int		ost;
	int		len;
	char	*a;

	len = ft_strl(p);
	if (!(a = malloc(sizeof(char *) * len + 1)))
	{
		free(a);
		return (NULL);
	}
	a[len] = '\0';
	while (p != 0)
	{
		len = len - 1;
		ost = p % 16;
		if (ost > 9)
			*(a + len) = (char)('a' - 10 + ost);
		else
			*(a + len) = (char)('0' + ost);
		p = p / 16;
	}
	return (a);
}

int		ft_print_p(int len, t_pt *list, char *s, unsigned long p)
{
	int i;
	int k;

	i = 0;
	if (list->width > (len + 2))
		k = list->width - (list->precision == 0 ? 0 : len) - 2;
	else
		k = 0;
	list->width = 0;
	if (list->precision < (int)ft_strlen(s) && p != 0)
		list->precision = ft_strlen(s);
	if (list->minus != 0)
	{
		i = ft_print_str("0x", 2);
		i += ft_write_u(s, ft_strlen(s), list, p);
		i += ft_print_wi_zer_str(k, ' ');
	}
	else
	{
		i = ft_print_wi_zer_str(k, ' ');
		i += ft_print_str("0x", 2);
		i += ft_write_u(s, list->precision, list, p);
	}
	return (i);
}

int		ft_type_p(va_list *a, t_pt *list)
{
	unsigned long	p;
	int				len;
	char			*s;
	int				i;

	i = 0;
	p = (unsigned long)va_arg(*a, void *);
	if (p != 0)
		s = conver_to_p(p);
	else
		s = (char *)ft_itoa(p);
	len = ft_strlen(s);
	if (list->precision < 0)
		list->precision = -1;
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = list->width * -1;
	}
	i = ft_print_p(len, list, s, p);
	free(s);
	return (i);
}
