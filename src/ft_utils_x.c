/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:11:00 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:52 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		func_parsing_one_x(t_pt *list, int w_len, int pr_len, size_t x)
{
	int		i;
	char	*s;

	i = 0;
	s = conver_to_x(x, list);
	if (list->minus == 1)
	{
		i = ft_print_pr_len_x(s, pr_len, x, list);
		i += ft_print_wi_zer_str(w_len, ' ');
	}
	else if (list->zero == 1 || (list->minus) != 1)
	{
		i = ft_print_wi_zer_str(w_len, ' ');
		i += ft_print_pr_len_x(s, pr_len, x, list);
	}
	return (i);
}

int		func_pasing_two_x(t_pt *list, int w_len, int pr_len, size_t x)
{
	int		i;
	char	*s;

	i = 0;
	s = conver_to_x(x, list);
	if (x >= 0)
	{
		w_len = w_len - pr_len;
		if (list->minus != 1)
		{
			i = ft_print_wi_zer_str(w_len, ' ');
			i += ft_print_pr_len_x(s, pr_len, x, list);
		}
		else
		{
			i = ft_print_pr_len_x(s, pr_len, x, list);
			i += ft_print_wi_zer_str(w_len, ' ');
		}
	}
	free(s);
	return (i);
}

int		func_parsing_tree_x(t_pt *list, int w_len, int pr_len, size_t x)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = conver_to_x(x, list);
	len = ft_strl(x);
	i = ft_print_wi_zer_str(pr_len, '0');
	i += ft_print_pr_len_x(s, (w_len > len) ? w_len : len, x, list);
	free(s);
	return (i);
}

int		func_parsing_four_x(t_pt *list, int w_len, int pr_len, size_t x)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = conver_to_x(x, list);
	len = ft_strl(x);
	if (w_len > pr_len)
	{
		i = func_pasing_two_x(list, w_len, pr_len, x);
		if (x < 0)
		{
			w_len = w_len - pr_len - (list->precision >= len);
			i = func_parsing_one_x(list, w_len, pr_len, x);
		}
	}
	else if (x >= 0)
	{
		pr_len -= (w_len > len) ? w_len : len;
		i = func_parsing_tree_x(list, w_len, pr_len, x);
	}
	else
		i = ft_print_pr_len_x(s, pr_len, x, list);
	free(s);
	return (i);
}

int		func_parsing_five_x(t_pt *list, int w_len, int pr_len, size_t x)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = conver_to_x(x, list);
	len = ft_strl(x);
	if (w_len <= len && pr_len <= len)
	{
		if (list->minus != 1 && w_len > pr_len)
			i = ft_print_str(s, len);
		else
			i = ft_print_pr_len_x(s, pr_len, x, list);
	}
	else
		i = func_parsing_four_x(list, w_len, pr_len, x);
	free(s);
	return (i);
}
