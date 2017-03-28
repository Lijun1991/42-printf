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




// intmax_t	number_to_print_signed(t_info *conver_info, va_list args)
// {
// 	if (ft_strlen(conver_info->len_mod) != 0)
// 	{
// 		if (ft_strncmp(conver_info->len_mod, "hh", 2) == 0)
// 			return ((char)va_arg(args, int));
// 		if (ft_strncmp(conver_info->len_mod, "h", 1) == 0)
// 			return ((short)va_arg(args, int));
// 		if (ft_strncmp(conver_info->len_mod, "l", 1) == 0)
// 			return (va_arg(args, long int));
// 		if (ft_strncmp(conver_info->len_mod, "ll", 2) == 0)
// 			return (va_arg(args, long long int));
// 		if (ft_strncmp(conver_info->len_mod, "j", 1) == 0)
// 			return (va_arg(args, intmax_t));
// 		if (ft_strncmp(conver_info->len_mod, "z", 1) == 0)
// 			return (va_arg(args, size_t));
// 	}
// 	return (va_arg(args, int)); 
// }


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

char	*print_convert_result(char *str, va_list args)
{
	t_info conver_info;
	str = get_flag_info(&conver_info, str);
	str = get_field_width(&conver_info, str);
	str = get_precision(&conver_info, str);
	str = get_length_modi(&conver_info, str);
	if (ft_strchr("diouxXDOUp", conver_info.conversion_specifier))
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

