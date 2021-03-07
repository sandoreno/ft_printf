/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:35:33 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:33:37 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser(t_pt *list, va_list *a, char **str)
{
	ft_lstnew_printf(list);
	while (**str == '-' || **str == '0' || **str == '*'
	|| **str == '.' || ft_isdigit(**str))
	{
		if (**str == '-')
			ft_parser_flag_minus(list, str);
		else if (**str == '0')
			ft_parser_flag_zero(list, str);
		else if (**str == '*')
			list->width = va_arg(*a, int);
		else if ((**str == '.' && *(*str + 1) == '*') && (*str = *str + 1))
			list->precision = va_arg(*a, int);
		else if (**str == '.')
			ft_parser_flag_dot(list, str);
		else if (ft_isdigit(**str))
			list->width = ft_parser_flag_digit(str);
		*str = *str + 1;
	}
	return (ft_type(str, a, list));
}

int		ft_parser_flag_minus(t_pt *list, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	list->minus = 1;
	list->zero = 0;
	*str = *str + 1;
	if (ft_isdigit(**str))
	{
		list->width = ft_atoi(*str);
		tmp = ft_itoa(list->width);
		i = ft_strlen(tmp);
		free(tmp);
	}
	*str = *str + i - 1;
	return (0);
}

int		ft_parser_flag_zero(t_pt *list, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	list->zero = 1;
	*str = *str + 1;
	if (ft_isdigit(**str))
	{
		list->width = ft_atoi(*str);
		tmp = ft_itoa(list->width);
		i = ft_strlen(tmp);
		free(tmp);
	}
	*str = *str + i - 1;
	return (0);
}

int		ft_parser_flag_dot(t_pt *list, char **str)
{
	int		i;
	char	*temp;

	i = 0;
	while (*(*str + 1) == '0')
		*str = *str + 1;
	list->precision = ft_atoi(*str + 1);
	temp = ft_itoa(list->precision);
	i = ft_strlen(temp);
	if (list->precision != 0)
		*str = *str + i;
	free(temp);
	return (0);
}

int		ft_parser_flag_digit(char **str)
{
	int		i;
	int		s;
	char	*temp;

	i = 0;
	s = ft_atoi(*str);
	temp = ft_itoa(s);
	i = ft_strlen(temp);
	*str = *str + i - 1;
	free(temp);
	return (s);
}
