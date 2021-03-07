/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:52 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:34:41 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		func_parsing_one_u(t_pt *list, int w_len, int pr_len, size_t d)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)ft_itoa_u(d);
	if (list->minus == 1)
	{
		i = ft_print_pr_len_u(s, pr_len, d, list);
		i += ft_print_wi_zer_str(w_len, ' ');
	}
	else if (list->zero == 1 || (list->minus) != 1)
	{
		i = ft_print_wi_zer_str(w_len, ' ');
		i += ft_print_pr_len_u(s, pr_len, d, list);
	}
	return (i);
}

int		func_pasing_two_u(t_pt *list, int w_len, int pr_len, size_t d)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)ft_itoa_u(d);
	if (d >= 0)
	{
		w_len = w_len - pr_len;
		if (list->minus != 1)
		{
			i = ft_print_wi_zer_str(w_len, ' ');
			i += ft_print_pr_len_u(s, pr_len, d, list);
		}
		else
		{
			i = ft_print_pr_len_u(s, pr_len, d, list);
			i += ft_print_wi_zer_str(w_len, ' ');
		}
	}
	free(s);
	return (i);
}

int		func_parsing_tree_u(t_pt *list, int w_len, int pr_len, size_t d)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = (char *)ft_itoa_u(d);
	len = ft_strlen(s);
	i = ft_print_wi_zer_str(pr_len, '0');
	i += ft_print_pr_len_u(s, (w_len > len) ? w_len : len, d, list);
	free(s);
	return (i);
}

int		func_parsing_four_u(t_pt *list, int w_len, int pr_len, size_t d)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = (char *)ft_itoa_u(d);
	len = ft_strlen(s);
	if (w_len > pr_len)
	{
		i = func_pasing_two_u(list, w_len, pr_len, d);
		if (d < 0)
		{
			w_len = w_len - pr_len - (list->precision >= len);
			i = func_parsing_one_u(list, w_len, pr_len, d);
		}
	}
	else if (d >= 0)
	{
		pr_len -= (w_len > len) ? w_len : len;
		i = func_parsing_tree_u(list, w_len, pr_len, d);
	}
	else
		i = ft_print_pr_len(s, pr_len, d, list);
	free(s);
	return (i);
}

int		func_parsing_five_u(t_pt *list, int w_len, int pr_len, size_t d)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = (char *)ft_itoa_u(d);
	len = ft_strlen(s);
	if (w_len <= len && pr_len <= len)
	{
		if (list->minus != 1 && w_len > pr_len)
			i = ft_print_str(s, len);
		else
			i = ft_print_pr_len_u(s, pr_len, d, list);
	}
	else
		i = func_parsing_four_u(list, w_len, pr_len, d);
	free(s);
	return (i);
}
