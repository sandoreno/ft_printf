/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:00:20 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:23 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_u(char *s, int pr_len, t_pt *list, size_t d)
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
			i = ft_print_pr_len_u(s, pr_len, d, list);
		else if (w_len != 0 && pr_len == -1)
			i = ft_print_w_len_u(s, w_len, d, list);
		else if (w_len != 0 && pr_len != -1)
			i = func_parsing_five_u(list, w_len, pr_len, d);
		else if (w_len == 0 && pr_len == -1)
		{
			pr_len = ft_strlen(s);
			i = ft_print_str(s, pr_len);
		}
	}
	return (i);
}

int		unslen(size_t n)
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

char	*a_fi(size_t num, size_t step, size_t i, char *arr)
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

char	*ft_itoa_u(size_t n)
{
	size_t		num;
	size_t		step;
	size_t		i;
	char		*arr;

	step = 1;
	i = 0;
	if (!(arr = malloc((unslen(n) + 1) * sizeof(char))))
		return (NULL);
	num = (size_t)n;
	if (n < 0)
	{
		*(arr + i++) = '-';
		num = (size_t)n * -1;
	}
	a_fi(num, step, i, arr);
	return (arr);
}

int		ft_type_u(va_list *a, t_pt *list)
{
	int		i;
	size_t	u;
	char	*s;
	int		len;
	int		maxlen;

	i = 0;
	u = va_arg(*a, unsigned int);
	if (list->precision < 0)
		list->precision = -1;
	s = (char *)ft_itoa_u(u);
	len = ft_strlen(s);
	if (len > list->precision && list->precision != -1)
		maxlen = len;
	else
		maxlen = list->precision;
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = list->width * -1;
	}
	i = ft_write_u(s, maxlen, list, u);
	free(s);
	return (i);
}
