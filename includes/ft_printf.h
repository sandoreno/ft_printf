/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:14:14 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/29 23:31:16 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_pt
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			type;
}				t_pt;

int				ft_printf(const char *str, ...);
void			ft_lstnew_printf(t_pt *arr);
int				ft_parser(t_pt *list, va_list *a, char **str);
int				ft_parser_flag_minus(t_pt *list, char **str);
int				ft_parser_flag_zero(t_pt *list, char **str);
int				ft_parser_flag_dot(t_pt *list, char **str);
int				ft_parser_flag_digit(char **str);
int				ft_type(char **str, va_list *a, t_pt *list);
int				ft_type_i_and_d(va_list *a, t_pt *list);
int				ft_print_zero(int d, int len, char *s);
int				ft_print_zero1(int d, int len, char *s);
int				ft_print_pr_len(char *s, int pr_len, int d, t_pt *list);
int				ft_print_w_len(char *s, int w_len, int d, t_pt *list);
int				func_parsing_one(t_pt *list, int w_len, int pr_len, int d);
int				func_pasing_two(t_pt *list, int w_len, int pr_len, int d);
int				func_parsing_tree(t_pt *list, int w_len, int pr_len, int d);
int				func_parsing_four(t_pt *list, int w_len, int pr_len, int d);
int				func_parsing_five(t_pt *list, int w_len, int pr_len, int d);
int				ft_write_d(char *s, int pr_len, t_pt *list, int d);
int				ft_type_c(va_list *a, t_pt *list);
int				ft_type_u(va_list *a, t_pt *list);
char			*ft_itoa_u(size_t n);
char			*a_fi(size_t num, size_t step, size_t i, char *arr);
int				unslen(size_t n);
int				ft_write_u(char *s, int pr_len, t_pt *list, size_t d);
int				func_parsing_five_u(t_pt *list, int w_len, int pr_len,
				size_t d);
int				func_parsing_four_u(t_pt *list, int w_len, int pr_len,
				size_t d);
int				func_parsing_tree_u(t_pt *list, int w_len, int pr_len,
				size_t d);
int				func_pasing_two_u(t_pt *list, int w_len, int pr_len,
				size_t d);
int				func_parsing_one_u(t_pt *list, int w_len, int pr_len,
				size_t d);
int				ft_print_w_len_u(char *s, int w_len, size_t d, t_pt *list);
int				ft_print_pr_len_u(char *s, int pr_len, size_t d, t_pt *list);
int				ft_print_zero1_u(size_t d, int len, char *s);
int				ft_print_zero_u(size_t d, int len, char *s);
int				ft_type_s(va_list *a, t_pt *list);
int				ft_write_s(char *s, int pr_len, t_pt *list);
int				checking_conditions_str(char *s, int w_len, int pr_len,
				t_pt *list);
int				ft_print_str(char *s, int len);
int				ft_print_wi_zer_str(int len, char c);
int				checking_conditions_str(char *s, int w_len, int pr_len,
				t_pt *list);
int				ft_type_p(va_list *a, t_pt *list);
int				ft_type_x(va_list *a, t_pt *list);
int				ft_write_x(char *s, int pr_len, t_pt *list, size_t x);
int				func_parsing_five_x(t_pt *list, int w_len, int pr_len,
				size_t x);
int				func_parsing_four_x(t_pt *list, int w_len, int pr_len,
				size_t x);
int				func_parsing_tree_x(t_pt *list, int w_len, int pr_len,
				size_t x);
int				func_pasing_two_x(t_pt *list, int w_len, int pr_len,
				size_t x);
int				func_parsing_one_x(t_pt *list, int w_len, int pr_len,
				size_t x);
int				ft_print_w_len_x(char *s, int w_len, size_t x, t_pt *list);
int				ft_print_pr_len_x(char *s, int pr_len, size_t x, t_pt *list);
int				ft_print_zero1_x(size_t x, int len, char *s, t_pt *list);
int				ft_print_zero_x(size_t x, int len, char *s, t_pt *list);
int				ft_strl(size_t x);
char			*conver_to_x(size_t x, t_pt *list);
int				ft_percent(t_pt *list, int i);
#endif
