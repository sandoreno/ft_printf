/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:02:04 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:33:58 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(char **str, va_list *a, t_pt *list)
{
	if ((**str == 'i' || **str == 'd') && (*str)++)
		return (ft_type_i_and_d(a, list));
	else if (**str == 'u' && (*str)++)
		return (ft_type_u(a, list));
	else if (**str == 'c' && (*str)++)
		return (ft_type_c(a, list));
	else if (**str == 's' && (*str)++)
		return (ft_type_s(a, list));
	else if (**str == 'p' && (*str)++)
		return (ft_type_p(a, list));
	else if ((**str == 'x' || **str == 'X') && (list->type = **str) && (*str)++)
		return (ft_type_x(a, list));
	else if (**str == '%' && (*str)++)
		return (ft_percent(list, 1));
	else
		return (0);
}

void	ft_lstnew_printf(t_pt *arr)
{
	arr->minus = 0;
	arr->zero = 0;
	arr->width = 0;
	arr->precision = -1;
	arr->type = 0;
}

int		ft_printf(const char *str, ...)
{
	int		i;
	char	*temp;
	t_pt	list;
	va_list	a;

	va_start(a, str);
	i = 0;
	temp = (char *)str;
	while (*temp != '\0')
	{
		if (*temp != '%')
		{
			ft_putchar_fd(*temp, 1);
			temp++;
			i++;
		}
		else
		{
			temp++;
			i += ft_parser(&list, &a, &temp);
		}
	}
	va_end(a);
	return (i);
}
