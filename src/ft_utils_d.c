/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:44 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:35 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		func_parsing_one(t_pt *list, int w_len, int pr_len, int d)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)ft_itoa(d);
	if (list->minus == 1)
	{
		i = ft_print_pr_len(s, pr_len, d, list);
		i += ft_print_wi_zer_str(w_len, ' ');
	}
	else if (list->zero == 1 || (list->minus) != 1)
	{
		i = ft_print_wi_zer_str(w_len, ' ');
		i += ft_print_pr_len(s, pr_len, d, list);
	}
	free(s);
	return (i);
}

int		func_pasing_two(t_pt *list, int w_len, int pr_len, int d)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)ft_itoa(d);
	if (d >= 0)
	{
		w_len = w_len - pr_len;
		if (list->minus != 1)
		{
			i = ft_print_wi_zer_str(w_len, ' ');
			i += ft_print_pr_len(s, pr_len, d, list);
		}
		else
		{
			i = ft_print_pr_len(s, pr_len, d, list);
			i += ft_print_wi_zer_str(w_len, ' ');
		}
	}
	free(s);
	return (i);
}

int		func_parsing_tree(t_pt *list, int w_len, int pr_len, int d)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = (char *)ft_itoa(d);
	len = ft_strlen(s);
	i = ft_print_wi_zer_str(pr_len, '0');
	i += ft_print_pr_len(s, (w_len > len) ? w_len : len, d, list);
	free(s);
	return (i);
}

int		func_parsing_four(t_pt *list, int w_len, int pr_len, int d)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = (char *)ft_itoa(d);
	len = ft_strlen(s);
	if (w_len > pr_len)
	{
		i = func_pasing_two(list, w_len, pr_len, d);
		if (d < 0)
		{
			w_len = w_len - pr_len - (list->precision >= len);
			i = func_parsing_one(list, w_len, pr_len, d);
		}
	}
	else if (d >= 0)
	{
		pr_len -= (w_len > len) ? w_len : len;
		i = func_parsing_tree(list, w_len, pr_len, d);
	}
	else
		i = ft_print_pr_len(s, pr_len, d, list);
	free(s);
	return (i);
}

int		func_parsing_five(t_pt *list, int w_len, int pr_len, int d)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = (char *)ft_itoa(d);
	len = ft_strlen(s);
	if (w_len <= len && pr_len <= len)
	{
		if (list->minus != 1 && w_len > pr_len)
			i = ft_print_str(s, len);
		else
			i = ft_print_pr_len(s, pr_len, d, list);
	}
	else
		i = func_parsing_four(list, w_len, pr_len, d);
	free(s);
	return (i);
}
