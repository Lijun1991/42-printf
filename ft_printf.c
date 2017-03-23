/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:21:38 by lwang             #+#    #+#             */
/*   Updated: 2017/03/14 21:21:42 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void    print_unsignedint_to_base_x(unsigned int nbr, unsigned int base)
{
	const char tab[] = "0123456789ABCDEF";

    if (nbr < base )
        ft_putchar(tab[nbr]);
    else if (nbr >= base && nbr <= 4294967295)
    {
        print_unsignedint_to_base_x(nbr / base, base);
        ft_putchar(tab[nbr % base]);
    }
}

void    print_unsignedint_to_base(unsigned int nbr, unsigned int base)
{
	const char tab[] = "0123456789abcdef";

    if (nbr < base )
        ft_putchar(tab[nbr]);
    else if (nbr >= base && nbr <= 4294967295)
    {
        print_unsignedint_to_base(nbr / base, base);
        ft_putchar(tab[nbr % base]);
    }
}

char	*get_length_modi(t_info *conver_info, char *str)
{	char *s;
	size_t len;

	conver_info->len_mod_info = (t_len_m*)malloc(sizeof(t_len_m) * 1); // malloc #2
	ft_bzero(conver_info->len_mod_info, sizeof(t_len_m));  // bzero can be used to initialize any data struct
	s = (char*)malloc(sizeof(char) * 2); // malloc #3;
	while (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z') 
	{
		*s = *str;
		s++;
		str++;
	}
	len = ft_strlen(s);
	if (len == 1)
	{
		if (s[0] == 'h')
			conver_info->len_mod_info->short_int = 'h';
		else if (s[0] == 'l')
			conver_info->len_mod_info->long_int = 'l';
		else if (s[0] == 'j')
			conver_info->len_mod_info->intmax = 'j';
		else if (s[0] == 'z')
			conver_info->len_mod_info->sizet = 'z';
	}
	else
	{
		if (s[0] == 'h')
			ft_strcpy(conver_info->len_mod_info->signed_un_char, "hh");
		else
			ft_strcpy(conver_info->len_mod_info->long_long_int, "ll");
	}
	return (str);
}


char	*get_precision(t_info *conver_info, char *str)
{
	if(*str == '.')
		str++;
	while (*str >= '1' && *str <= '9')
	{
		conver_info->precision = ft_atoi(str);
		while (*str >= '1' && *str <= '9')
		str++;
	}
	return (str);
}

char	*get_field_width(t_info *conver_info, char *str)
{
	while (*str >= '1' && *str <= '9')
	{
		conver_info->field_width = ft_atoi(str);
		while (*str >= '1' && *str <= '9')
		str++;
	}
	return (str);
}

char	*get_flag_info(t_info *conver_info, char *str)
{
	conver_info->flag_info = (t_flag*)malloc(sizeof(t_flag)* 1);   // malloc #1
	ft_bzero(conver_info->flag_info, sizeof(t_flag));
	while (*str == '#' || *str == '-' || *str == '+' || *str == ' ' || *str == '0') 
	{
		if (*str == '#')
			conver_info->flag_info->hash = '#';
		else if (*str == '-')
			conver_info->flag_info->minus = '-';
		else if (*str == '+')
			conver_info->flag_info->plus = '+';
		else if (*str == ' ')
			conver_info->flag_info->space = ' ';
		else if (*str == '0')
			conver_info->flag_info->zero = '0';
		else
			(ft_putstr("something wrong with flags"));
		str++;
	}
	return (str);
}

char	*print_convert_result(char *str, va_list args)
{
	t_info conver_info;
	str = get_flag_info(&conver_info, str);
	str = get_field_width(&conver_info, str);
	str = get_precision(&conver_info, str);
	str = get_length_modi(&conver_info, str);
	if (*str == 'd' || *str == 'i')
	{
		int nbr;
		nbr = va_arg(args, int); 
		ft_putnbr(nbr);
		str++;
	}
	if (*str == 'o')
	{
		print_unsignedint_to_base(va_arg(args, unsigned int), 8);
		str++;
	}
	if (*str == 'u')
	{
		print_unsignedint_to_base(va_arg(args, unsigned int), 10);
		str++;
	}
	if (*str == 'x')
	{
		print_unsignedint_to_base(va_arg(args, unsigned int), 16);
		str++;
	}
	if (*str == 'X')
	{
		print_unsignedint_to_base_x(va_arg(args, unsigned int), 16);
		str++;
	}
	// ft_putchar(conver_info.flag_info->minus);
	// ft_putchar(conver_info.flag_info->plus);
	// ft_putchar(conver_info.flag_info->space);
	// ft_putchar(conver_info.flag_info->zero);
	// ft_putchar(conver_info.flag_info->hash);
	// ft_putnbr(conver_info.field_width);
	// ft_putnbr(conver_info.precision);
	// ft_putstr(conver_info.len_mod_info->long_long_int);
	return (str);
}

void	ft_printf(char *format, ...)
{
	va_list args;
	char *str;

	va_start(args, format);
	str = (char*)format;

	while (*str != '\0')
	{
		while ((*str != '%') && (*str != '\0'))
		{
			ft_putchar(*str); // print string before % sign
			str++;
		}
		if (*str == '%')
			str++;
		if (*str != '\0')
			str = print_convert_result(str, args); // in: "% to null"   out: print %sign to %sign or %sing to '\0'
	}
	va_end(args);
}

