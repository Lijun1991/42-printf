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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <locale.h>
#include <wchar.h>
#include "./libft/libft.h"

typedef struct	s_flag
{
	char hash;
	char minus;
	char plus;
	char space;
	char zero;
}				t_flag;

typedef struct	s_info
{
	int	field_width; 
	int	precision;
	char conversion_specifier;
	t_flag *flag_info;
	char len_mod[3];
	char pre_sign[3];
}				t_info;

//printf.c
void	ft_printf(char *format, ...);
char	*print_convert_result(char *str, va_list args);
int	print_sign(intmax_t nbr, t_info *conver_info, int sign);
void	print_str(char *str);

//get_conversion_info.c
char	*get_length_modi(t_info *conver_info, char *str);
char	*get_precision(t_info *conver_info, char *str);
char	*get_field_width(t_info *conver_info, char *str);
char	*get_flag_info(t_info *conver_info, char *str);
void	get_less_conversion_specifier(char s, t_info *conver_info);

//print_number.c
void	print_number_conversion(t_info *conver_info, char c, va_list args);
void	print_result_capx(intmax_t nbr, t_info *conver_info, int base);
void	print_result(intmax_t nbr, t_info *conver_info, int base);
intmax_t	number_to_print_signed(t_info *conver_info, va_list args);
intmax_t	number_to_print_unsigned(t_info *conver_info, va_list args);

//print_string
void	print_string(t_info *conver_info, va_list args, int sign);
void	print_regular_string(t_info *conver_info, char *s);
void	print_reg_str_precision(t_info *conver_info, char *s);
void	ft_putstr_len(char *s, int i);
void	print_wide_string(t_info *conver_info, wchar_t *ws, int sign);

//print_char.c
void	print_char_conversion(t_info *conver_info, char c, va_list args);
void	print_char(t_info *conver_info, va_list args, int sign);
void	print_regular_char(t_info *conver_info, char chara, int sign);
void	print_wide_char(t_info *conver_info, wchar_t wchara, int sign);
void	print_wchar(t_info *conver_info, char *str, int j, int sign);

//print_number_helper.c
void	print_nbr(t_info *conver_info, char *str, int sign, int len);
void	print_exit_precision_left(t_info *conver_info, char *str, int sign, int len);
void	print_no_precision_left(t_info *conver_info, char *str, int sign, int len);
void	print_exit_precision(t_info *conver_info, char *str, int sign, int len);
void	print_no_precision(t_info *conver_info, char *str, int sign, int len);

#endif
