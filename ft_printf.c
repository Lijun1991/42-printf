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

// void    print_unsignedint_to_base_x(unsigned int nbr, unsigned int base)
// {
// 	const char tab[] = "0123456789ABCDEF";

//     if (nbr < base )
//         ft_putchar(tab[nbr]);
//     else if (nbr >= base && nbr <= 4294967295)
//     {
//         print_unsignedint_to_base_x(nbr / base, base);
//         ft_putchar(tab[nbr % base]);
//     }
// }

// void    print_unsignedint_to_base(unsigned int nbr, unsigned int base)
// {
// 	const char tab[] = "0123456789abcdef";

//     if (nbr < base )
//         ft_putchar(tab[nbr]);
//     else if (nbr >= base && nbr <= 4294967295)
//     {
//         print_unsignedint_to_base(nbr / base, base);
//         ft_putchar(tab[nbr % base]);
//     }
// }


char	*get_length_modi(t_info *conver_info, char *str)
{	
	strcpy(conver_info->len_mod, "\0\0\0");
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		strcpy(conver_info->len_mod, "ll");
		str++;
		str++;
	}
	else if (ft_strncmp(str, "hh", 2) == 0)
	{
		strcpy(conver_info->len_mod, "hh");
		str++;
		str++;
	}
	else if (ft_strncmp(str, "l", 1) == 0)
	{
		strcpy(conver_info->len_mod, "l");
		str++;
	}
	else if (ft_strncmp(str, "h", 1) == 0)
	{
		strcpy(conver_info->len_mod, "h");
		str++;
	}
	else if (ft_strncmp(str, "j", 1) == 0)
	{
		strcpy(conver_info->len_mod, "j");
		str++;
	}
	else if (ft_strncmp(str, "z", 1) == 0)
	{
		strcpy(conver_info->len_mod, "z");
		str++;
	}
	conver_info->conversion_specifier = *str;
	return (str);
}


char	*get_precision(t_info *conver_info, char *str)
{
	conver_info->precision = 1;
	if(*str == '.')
		str++;
	if (*str >= '0' && *str <= '9')
		conver_info->precision = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

char	*get_field_width(t_info *conver_info, char *str)
{
	conver_info->field_width = -1;
	if (*str >= '1' && *str <= '9')
		conver_info->field_width = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
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
			conver_info->flag_info->zero = 'y';
		else
			(ft_putstr("something wrong with flags"));
		str++;
	}
	return (str);
}

void	get_less_conversion_specifier(char s, t_info *conver_info)
{
	if (s == 'i')
		conver_info->conversion_specifier = 'd';
	if (s == 'p')
	{
		strcpy(conver_info->len_mod, "l");
		conver_info->conversion_specifier = 'x';
	}
	if (s == 'D')
	{
		strcpy(conver_info->len_mod, "l");
		conver_info->conversion_specifier = 'd';
	}
	if (s == 'O')
	{
		strcpy(conver_info->len_mod, "l");
		conver_info->conversion_specifier = 'o';
	}
	if (s == 'U')
	{
		strcpy(conver_info->len_mod, "l");
		conver_info->conversion_specifier = 'u';
	}
}

intmax_t	number_to_print_signed(t_info *conver_info, va_list args)
{
	if (ft_strlen(conver_info->len_mod) != 0)
	{
		if (ft_strncmp(conver_info->len_mod, "hh", 2) == 0)
			return ((char)va_arg(args, int));
		if (ft_strncmp(conver_info->len_mod, "h", 1) == 0)
			return ((short)va_arg(args, int));
		if (ft_strncmp(conver_info->len_mod, "l", 1) == 0)
			return (va_arg(args, long int));
		if (ft_strncmp(conver_info->len_mod, "ll", 2) == 0)
			return (va_arg(args, long long int));
		if (ft_strncmp(conver_info->len_mod, "j", 1) == 0)
			return (va_arg(args, intmax_t));
		if (ft_strncmp(conver_info->len_mod, "z", 1) == 0)
			return (va_arg(args, size_t));
	}
	return (va_arg(args, int)); 
}

intmax_t	number_to_print_unsigned(t_info *conver_info, va_list args)
{
	if (ft_strlen(conver_info->len_mod) != 0)
	{
		if (ft_strncmp(conver_info->len_mod, "hh", 2) == 0)
			return ((unsigned char)va_arg(args, unsigned int));
		if (ft_strncmp(conver_info->len_mod, "h", 1) == 0)
			return ((unsigned short)va_arg(args, unsigned int));
		if (ft_strncmp(conver_info->len_mod, "l", 1) == 0)
			return (va_arg(args, unsigned long int));
		if (ft_strncmp(conver_info->len_mod, "ll", 2) == 0)
			return (va_arg(args, unsigned long long int));
		if (ft_strncmp(conver_info->len_mod, "j", 1) == 0)
			return (va_arg(args, uintmax_t));
		if (ft_strncmp(conver_info->len_mod, "z", 1) == 0)
			return (va_arg(args, size_t));
	}
	return (va_arg(args, unsigned int)); 
}

void	print_str(char *str)
{
	while(*str != '\0' && *str == '*')
		str++;
	while (*str != '\0' && *str != '*')
	{
		ft_putchar(*str);
		str++;
	}
}

int	print_sign(intmax_t nbr, t_info *conver_info, int sign)
{
	char* pre_sign;

	pre_sign = "\0\0";
	if (sign == 1)
		pre_sign = "-\0";
	else if (conver_info->flag_info->plus == '+' && sign != 1 && conver_info->conversion_specifier == 'd')
	{
		pre_sign = "+\0";
		sign = 1;
	}
	else if (conver_info->flag_info->space == ' ' && sign != 1 && conver_info->conversion_specifier == 'd')
	{
		pre_sign = " \0";
		sign = 1;
	}
	else if (conver_info->conversion_specifier == 'x' && ft_strncmp(conver_info->len_mod, "l", 1) == 0)
	{
		pre_sign = "0x\0";
		sign = 2;
	}
	else if (conver_info->conversion_specifier == 'x' && conver_info->flag_info->hash == '#')
	{
		pre_sign = "0x\0";
		sign = 2;
	}
	else if (conver_info->conversion_specifier == 'X' && conver_info->flag_info->hash == '#')
	{
		pre_sign = "0X\0";
		sign = 2;
	}
	ft_strcpy(conver_info->pre_sign, pre_sign);
	return (sign);
}

void	print_no_precision(t_info *conver_info, char *str, int sign, int len)
{
	int i;

	i = 0;
	if (conver_info->precision == 1)
	{
		if (len + sign >= conver_info->field_width)
		{
			ft_putstr(conver_info->pre_sign);
			print_str(str);
		}
		else
		{
			i = conver_info->field_width - len - sign;
			if (conver_info->flag_info->zero == 'y')
			{
				ft_putstr(conver_info->pre_sign);
				while (i-- > 0) 
					ft_putchar('0');
			}
			else
			{
				while (i-- > 0) 
					ft_putchar(' ');
				ft_putstr(conver_info->pre_sign);
			}	
			print_str(str);
		}
	}
}

void	print_exit_precision(t_info *conver_info, char *str, int sign, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (conver_info->precision != 1)
	{
		if (len >= conver_info->precision)
		{
			if (conver_info->precision + sign >= conver_info->field_width)
			{
				ft_putstr(conver_info->pre_sign);
				print_str(str);
			}
			else
			{
				i = conver_info->field_width - conver_info->precision - sign;
				while (i-- > 0) 
					ft_putchar(' ');
				ft_putstr(conver_info->pre_sign);
				print_str(str);
			}
		}
		else
		{
			if (conver_info->precision + sign >= conver_info->field_width)
			{
				j = conver_info->precision - len;
				ft_putstr(conver_info->pre_sign);
				while (j-- > 0) 
					ft_putchar('0');
				print_str(str);
			}
			else
			{
				i = conver_info->field_width - conver_info->precision - sign;
				while (i-- > 0) 
					ft_putchar(' ');
				ft_putstr(conver_info->pre_sign);
				j = conver_info->precision - len;
				while (j-- > 0)
					ft_putchar('0');
				print_str(str);	
			}
		}
	}
}

void	print_no_precision_left(t_info *conver_info, char *str, int sign, int len)
{
	int i;

	i = 0;
	if (conver_info->precision == 1)
	{
		if (len + sign >= conver_info->field_width)
		{
			ft_putstr(conver_info->pre_sign);
			print_str(str);
		}
		else
		{
			i = conver_info->field_width - len - sign;
			ft_putstr(conver_info->pre_sign);
			print_str(str);
			while (i-- > 0) 
				ft_putchar(' ');
		}
	}
}

void	print_exit_precision_left(t_info *conver_info, char *str, int sign, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (conver_info->precision != 1)
	{
		if (len >= conver_info->precision)
		{
			if (conver_info->precision + sign >= conver_info->field_width)
			{
				ft_putstr(conver_info->pre_sign);
				print_str(str);
			}
			else
			{
				i = conver_info->field_width - conver_info->precision - sign;
				ft_putstr(conver_info->pre_sign);
				print_str(str);
				while (i-- > 0) 
					ft_putchar(' ');  
			}
		}
		else
		{
			if (conver_info->precision + sign >= conver_info->field_width)
			{
				j = conver_info->precision - len;
				ft_putstr(conver_info->pre_sign);
				while (j-- > 0) 
					ft_putchar('0');
				print_str(str);
			}
			else
			{
				j = conver_info->precision - len;
				ft_putstr(conver_info->pre_sign);
				while (j-- > 0)
					ft_putchar('0');
				print_str(str);
				i = conver_info->field_width - conver_info->precision - sign;
				while (i-- > 0) 
					ft_putchar(' ');
			}
		}
	}
}

void	print_nbr(t_info *conver_info, char *str, int sign, int len)
{
	if (conver_info->flag_info->minus != '-')
	{
		print_no_precision(conver_info, str, sign, len);
		print_exit_precision(conver_info, str, sign, len);
	}
	else
	{
		print_no_precision_left(conver_info, str, sign, len);
		print_exit_precision_left(conver_info, str, sign, len);
	}
}

void	print_result(intmax_t nbr, t_info *conver_info, int base)
{
	int i;
	char str[50];
	int len;
	int sign;
	const char tab[] = "0123456789abcdef";

	i = 49;
	sign = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		sign = 1;
	}
	sign = print_sign(nbr, conver_info, sign);
	str[49] = '\0';
	
	while (nbr >= 1)
	{
		str[--i] = (tab[nbr % base]);
		nbr /= base;
	}
	len = 49 - i;

	while (i >= 0)
		str[--i] = '*'; 
	// ft_putstr(str); // is it becaluse here ??????? l/ll/h/hh not working for d!!!! .......................
	print_nbr(conver_info, str, sign, len);
}

void	print_result_capx(intmax_t nbr, t_info *conver_info, int base)
{
	int i;
	char str[50];
	int len;
	int sign;
	const char tab[] = "0123456789ABCDEF";

	i = 49;
	sign = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		sign = 1;
	}
	sign = print_sign(nbr, conver_info, sign);
	str[49] = '\0';
	
	while (nbr >= 1)
	{
		str[--i] = (tab[nbr % base]);
		nbr /= base;
	}
	len = 49 - i;

	while (i >= 0)
		str[--i] = '*';  
	print_nbr(conver_info, str, sign, len);
}

void	print_number_conversion(t_info *conver_info, char c, va_list args)
{
	intmax_t nbr;
	get_less_conversion_specifier(c, conver_info);
	if (conver_info->conversion_specifier == 'd')
		nbr = number_to_print_signed(conver_info, args); // d, int converted to singed decimal, l/ll/h/hh/j/z int converted to correspons value
	else
		nbr = number_to_print_unsigned(conver_info, args);
	// printf("nbr is %ld", nbr);

	if (conver_info->conversion_specifier == 'd' || conver_info->conversion_specifier == 'u')
		print_result(nbr, conver_info, 10);
	else if (conver_info->conversion_specifier == 'o')
		print_result(nbr, conver_info, 8);
	else if (conver_info->conversion_specifier == 'x')
		print_result(nbr, conver_info, 16);
	else if (conver_info->conversion_specifier == 'X')
		print_result_capx(nbr, conver_info, 16);
	// else if (conver_info->conversion_specifier == 'p')
	// 	print_result(nbr, conver_info, 16);

}

void	print_regular_char(t_info *conver_info, char chara)
{
	int i;

	if (conver_info->flag_info->minus == '-')
	{
		i = conver_info->field_width - 1;
		ft_putchar(chara);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		i = conver_info->field_width - 1;
		while (i-- > 0)
		{
			if (conver_info->flag_info->zero == 'y')
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(chara);
	}
}

void	print_wchar(t_info *conver_info, char *str, int j)
{
	int i;

	if (conver_info->flag_info->minus == '-')
	{
		i = conver_info->field_width - j;
		write(1, str, j);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		i = conver_info->field_width - j;
		while (i-- > 0)
		{
			if (conver_info->flag_info->zero == 'y')
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		write(1, str, j);
	}
}

void	print_wide_char(t_info *conver_info, wchar_t wchara)
{
	char str[4];

	if (wchara <= 0x7F)
		print_regular_char(conver_info, wchara);
	else if (wchara <= 0x7FF)
	{
		str[0] = (((wchara & 0x07c0) >> 6) + 0xc0);   // ???? why 0x07c0????? and why + 0xc0???
		str[1] = ((wchara & 0x03F0) + 0x80);
		print_wchar(conver_info, str, 2);
	}
	else if (wchara <= 0xFFFF)
	{
		str[0] = (((wchara & 0xF000) >> 12) + 0xE0);
		str[1] = (((wchara & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wchara & 0x003F) + 0x80);
		print_wchar(conver_info, str, 3);
	}
	else if (wchara <= 0x10FFFF)
	{
		str[0] = (((wchara & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wchara & 0x03F000) >> 12) + 0x80);
		str[2] = (((wchara & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wchara & 0x003F) + 0x80);
		print_wchar(conver_info, str, 4);
	}
}	

void	print_char(t_info *conver_info, va_list args)
{
	char chara;
	wchar_t wchara;

	if (ft_strncmp(conver_info->len_mod, "l", 1) == 0)
	{
		wchara = va_arg(args, wint_t);
		print_wide_char(conver_info, wchara);
	}
	else
	{
		chara = (unsigned char)va_arg(args, int);
		print_regular_char(conver_info, chara);
	}
}

void	print_reg_str_precision(t_info *conver_info, char *s)
{
	int i;
	int j;

	i = conver_info->field_width - ft_strlen(s);
	j = 
	if (conver_info->flag_info->minus == '-')
	{
		ft_putstr_len(s, conver_info->precision);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
		{
			if (conver_info->flag_info->zero == 'y')
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putstr(s);
	}
}

void	print_regular_string(t_info *conver_info, char *s, int i)
{
	i = conver_info->field_width - ft_strlen(s);
	if (conver_info->precision == 1)
	{
		if (conver_info->flag_info->minus == '-')
		{
			ft_putstr(s);
			while (i-- > 0)
				ft_putchar(' ');
		}
		else
		{
			while (i-- > 0)
			{
				if (conver_info->flag_info->zero == 'y')
					ft_putchar('0');
				else
					ft_putchar(' ');
			}
			ft_putstr(s);
		}
	}
	else
		print_reg_str_precision(conver_info, s);
}

void	print_wide_string(t_info *conver_info, wchar_t *ws)
{

}

void	print_string(t_info *conver_info, va_list args)
{
	char *s;
	wchar_t *ws;

	if (ft_strncmp(conver_info->len_mod, "l", 1) == 0)
	{
		ws = va_arg(args, wchar_t*);
		print_wide_string(conver_info, ws);
	}
	else
	{
		s = va_arg(args, char*);
		print_regular_string(conver_info, s, 0);
	}
}

void	print_char_conversion(t_info *conver_info, char c, va_list args)
{
	if (c == 'C' || c == 'S')
	{
		strcpy(conver_info->len_mod, "l");
		conver_info->conversion_specifier = ft_tolower(c);
	}
	if (conver_info->conversion_specifier == 'c')
		print_char(conver_info, args);
	if (conver_info->conversion_specifier == 's')
	{
		print_string(conver_info, args);
	}
}

char	*print_convert_result(char *str, va_list args)
{
	t_info conver_info;
	str = get_flag_info(&conver_info, str);
	str = get_field_width(&conver_info, str);
	str = get_precision(&conver_info, str);
	str = get_length_modi(&conver_info, str);
	// ft_putchar(conver_info.conversion_specifier);
	if (ft_strchr("diouxXDOUp", conver_info.conversion_specifier))  // ll/l/hh/h/j/z ouxX not wok=rking ????????
		print_number_conversion(&conver_info, conver_info.conversion_specifier, args);
	else if (ft_strchr("cCsS", conver_info.conversion_specifier))
		print_char_conversion(&conver_info, conver_info.conversion_specifier, args);
	else
		ft_putstr("unsupported conversion specifier");
	str++;

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
		if (*str != '\0')        // WHY two % doesn't print number????????
			str = print_convert_result(str, args); // in: "% to null"   out: print %sign to %sign or %sing to '\0'
	}
	va_end(args);
}
