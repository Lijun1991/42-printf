/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:04:32 by lwang             #+#    #+#             */
/*   Updated: 2017/03/17 11:04:35 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>
# include "./libft/libft.h"

# define RED "\e[31;3m"
# define BLUE "\e[32;3m"
# define GREE "e[36;3m"
# define YELLOW "\e[33;3m"
# define PURPLE "\e[35;3m"

# define CLN "\e[0m"

typedef struct		s_string
{
	int		precision;
	int		is_char;
	char	chara;
	wchar_t	wchara;
}					t_string;

typedef struct		s_flag
{
	char	hash;
	char	minus;
	char	plus;
	char	space;
	char	zero;
}					t_flag;

typedef struct		s_info
{
	int		field_width;
	int		precision;
	char	conversion_specifier;
	t_flag	*flag_info;
	char	len_mod[3];
	char	pre_sign[3];
	int		count;
	int		iszero;
	int		is_nopre;
	int		is_dot;
	int		is_dot_zero;
	int		is_dot_pre;
	int		isp;
	int		sign;
	char	star;
}					t_info;
/*
** printf.c
*/
int					ft_printf(char *format, ...);
char				*print_convert_result(char *str, va_list args, \
	t_info *conver_info);
char				*get_flag_info(t_info *conver_info, char *str);
int					print_sign(t_info *conver_info, int sign);
/*
** get_conversion_info.c
*/
char				*get_length_modi(t_info *conver_info, char *str);
char				*get_precision(t_info *conver_info, char *str, \
	va_list args);
char				*get_field_width(t_info *conver_info, char *str, \
	va_list args);
/*
** print_number_conversion.c
*/
void				get_less_conversion_specifier(char s, t_info *conver_info);
void				print_number_conversion(t_info *conver_info, \
	char c, va_list args);
void				print_result_capx(unsigned long long nbr, \
	t_info *conver_info, int base);
void				print_result(unsigned long long nbr, \
	t_info *conver_info, int base);
void				print_result_d(long long nbr, \
	t_info *conver_info, int base);
/*
** print_number.c
*/
long long			number_to_print_signed(t_info *conver_info, va_list args);
unsigned long long	number_to_print_unsigned(t_info *conver_info, va_list args);
void				print_nbr(t_info *conver_info, char *str, int len);
void				print_exit_precision_left(t_info *conver_info, \
	char *str, int len);
/*
** print_nbr_str.c
*/
void				print_no_precision(t_info *conver_info, char *str, int len);
void				print_str(char *str, t_info *conver_info);
/*
** print_nbr_helper.c
*/
void				print_no_precision_left(t_info *conver_info, \
	char *str, int len);
void				print_exit_precision(t_info *conver_info, \
	char *str, int len);
/*
** print_char_conversion.c
*/
void				print_char_conversion(t_info *conver_info, \
	char c, va_list args);
void				print_char(t_info *conver_info, va_list args, int sign);
void				print_regular_char(t_info *conver_info, \
	char chara, int sign);
void				print_wide_char(t_info *conver_info, \
	wchar_t wchara, int sign);
void				print_wchar(t_info *conver_info, char *str, \
	int j, int sign);
/*
** print_string.c
*/
void				print_string(t_info *conver_info, va_list args, int sign);
void				print_null(t_info *conver_info);
void				print_reg_string(t_info *conver_info, \
	char *s, int i, int j);
void				print_reg_str_precision(t_info *conver_info, \
	char *s, int i, int j);
void				ft_putstr_len(char *s, int i, t_info *conver_info);
/*
** print_wide_sting.c
*/
void				print_wide_string(t_info *conver_info, wchar_t *ws, \
	int sign);
void				print_w_str_precision(t_info *conver_info, \
	wchar_t *ws, int len, int sign);
/*
** print_wstr_helper.c
*/
void				ft_putwstr_len(wchar_t *ws, t_info *conver_info, \
	int precision, int sign);
int					ft_wstrlen(wchar_t *tmp);
/*
** helper.c
*/
void				print_nbr_helper(t_info *conver_info, int i, char c);
void				write_helper(t_info *conver_info, char *str, int j);
void				print_space_helper(t_info *conver_info, int i);
void				print_w_char_helper(t_info *conver_info, \
	wchar_t *ws, int sign);
void				put_str_helper(t_info *conver_info, int i, char *s);
/*
** print_invalid_get_info.c
*/
void				print_unvalid_conversion_specifier(\
	t_info *conver_info, char s);
int					get_pre(wchar_t *ws, int precision);

#endif
