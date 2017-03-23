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

// void	print_way_1(t_info *conver_info, int nbr)
// {
// 	if (STATUS1)
// 		ft_putchar('+');
// 	else if (STATUS2)
// 		ft_putchar('+');
// 	else if (STATUS3)
// 		ft_putchar('+');
// 	else if (STATUS4)
// 		ft_putchar(' ');
// 	else
// 		ft_putstr("more status needed1");
// 	// if (STATUS5)
// 	// 	ft_putchar(' ');
// 	ft_putnbr(nbr);
// }

// void	print_way_2(t_info *conver_info, int nbr)
// {
// 	if (STATUS1)
// 	{
// 		int i;

// 		i = 0;
// 		ft_putchar('+');
// 		ft_putnbr(nbr);
// 		while (i++ < conver_info->field_width - ft_nbrlen(nbr) - 1)
// 			ft_putchar(' ');
// 	}
// 	else if (STATUS2)
// 	{
// 		int i;

// 		i = 0;
// 		ft_putchar('+');
// 		ft_putnbr(nbr);
// 		while (i++ < conver_info->field_width - ft_nbrlen(nbr) - 1)
// 			ft_putchar(' ');
// 	}
// 	else if (STATUS3)
// 	{
// 		int i;

// 		i = 0;
// 		while (i++ < conver_info->field_width - ft_nbrlen(nbr) - 1)
// 			ft_putchar(' ');
// 		ft_putchar('+');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS4)
// 	{
// 		int i;

// 		i = 0;
// 		while (i++ < conver_info->field_width - ft_nbrlen(nbr))
// 			ft_putchar(' ');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS5)
// 	{
// 		int i;

// 		i = 0;
// 		while (i++ < conver_info->field_width - ft_nbrlen(nbr))
// 			ft_putchar(' ');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS6)
// 	{
// 		int i;

// 		i = 0;
// 		while (i++ < conver_info->field_width - ft_nbrlen(nbr))
// 			ft_putchar(' ');
// 		ft_putnbr(nbr);
// 	}
// 	else
// 		ft_putstr("more status needed2");
// }

// void	print_way_3(t_info *conver_info, int nbr)
// {
// 	if (STATUS1)
// 	{
// 		int i;
// 		int j;

// 		i = 0;
// 		j = 0;
// 		ft_putchar('+');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 		while (j++ < conver_info->field_width - conver_info->precision - 1)
// 			ft_putchar(' ');
// 	}
// 	else if (STATUS2)
// 	{
// 		int i;
// 		int j;

// 		i = 0;
// 		j = 0;
// 		ft_putchar('+');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 		while (j++ < conver_info->field_width - conver_info->precision - 1)
// 			ft_putchar(' ');
// 	}
// 	else if (STATUS3)
// 	{
// 		int i;
// 		int j;

// 		i = 0;
// 		j = 0;
// 		while (j++ < conver_info->field_width - conver_info->precision - 1)
// 			ft_putchar(' ');
// 		ft_putchar('+');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS4)
// 	{
// 		int i;
// 		int j;

// 		i = 0;
// 		j = 0;
// 		while (j++ < conver_info->field_width - conver_info->precision)
// 			ft_putchar(' ');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS5)
// 	{
// 		int i;
// 		int j;

// 		i = 0;
// 		j = 0;
// 		while (j++ < conver_info->field_width - conver_info->precision)
// 			ft_putchar(' ');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS6)
// 	{
// 		int i;
// 		int j;

// 		i = 0;
// 		j = 0;
// 		while (j++ < conver_info->field_width - conver_info->precision)
// 			ft_putchar(' ');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else
// 		ft_putstr("more status needed3");
// }

// void	print_way_4(t_info *conver_info, int nbr)
// {
// 	if (STATUS1)
// 	{
// 		int i;

// 		i = 0;
// 		ft_putchar('+');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS2) 
// 	{
// 		int i;

// 		i = 0;
// 		ft_putchar('+');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS3) // same as 1
// 	{
// 		int i;

// 		i = 0;
// 		ft_putchar('+');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS4) // just remove printing +
// 	{
// 		int i;

// 		i = 0;
// 		ft_putchar(' ');
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS5)
// 	{
// 		int i;

// 		i = 0;
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else if (STATUS6) // more status needed here ......
// 	{
// 		int i;

// 		i = 0;
// 		while (i++ < conver_info->precision - ft_nbrlen(nbr))
// 			ft_putchar('0');
// 		ft_putnbr(nbr);
// 	}
// 	else 
// 		ft_putstr("more status needed4");
// }

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
	conver_info->length_modifier = *str;
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
	else if (len == 2)
	{
		if (s[0] == 'h')
			ft_strcpy(conver_info->len_mod_info->signed_un_char, "hh");
		else
			ft_strcpy(conver_info->len_mod_info->long_long_int, "ll");
	}
	else
		ft_putstr("unqualify length modifier");
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

void	get_less_conversion_specifier(char s, t_info *conver_info)
{
	if (s == 'i')
		s = 'd';
	if (s == 'p')
		s = 'x';
	if (s == 'D')
	{
		conver_info->len_mod_info->long_int = 'l';
		s = 'd';
	}
	if (s == 'O')
	{
		conver_info->len_mod_info->long_int = 'l';
		s = 'o';
	}
	if (s == 'U')
	{
		conver_info->len_mod_info->long_int = 'l';
		s = 'u';
	}
}

intmax_t	number_to_print_signed(t_info *conver_info, va_list args)
{
	if (conver_info->len_mod_info)
	{
		if (ft_strncmp(conver_info->len_mod_info->signed_un_char, "hh", 2) == 0)
			return ((char)va_arg(args, int));
		if (conver_info->len_mod_info->short_int == 'h')
			return ((short)va_arg(args, int));
		if (conver_info->len_mod_info->long_int == 'l')
			return (va_arg(args, long int));
		if (ft_strncmp(conver_info->len_mod_info->long_long_int, "ll", 2) == 0)
			return (va_arg(args, long long int));
		if (conver_info->len_mod_info->intmax == 'j')
			return (va_arg(args, intmax_t));
		if (conver_info->len_mod_info->sizet == 'u')
			return (va_arg(args, size_t));
	}
	return (va_arg(args, int)); 
}

intmax_t	number_to_print_unsigned(t_info *conver_info, va_list args, char s)
{
	if (s == 'u')
		return (va_arg(args, unsigned int));
	if (s == 'o')
		return (va_arg(args, unsigned int));
	if (s == 'x')
		return (va_arg(args, unsigned int));
	if (s == 'X')
		return (va_arg(args, unsigned int));
	return (0);
}

void	print_number_conversion(t_info *conver_info, char c, va_list args)
{
	intmax_t nbr;
	get_less_conversion_specifier(c, conver_info);
	if (c == 'd')
		nbr = number_to_print_signed(conver_info, args); // d, int converted to singed decimal, l/ll/h/hh/j/z int converted to correspons value
	else
		nbr = number_to_print_unsigned(conver_info, args, c);
	ft_putnbr(nbr);
}

char	*print_convert_result(char *str, va_list args)
{
	t_info conver_info;
	str = get_flag_info(&conver_info, str);
	str = get_field_width(&conver_info, str);
	str = get_precision(&conver_info, str);
	str = get_length_modi(&conver_info, str);
	while (ft_strchr("diouxXDOUp", conver_info->conversion_modifier))
		print_number_conversion(&conver_info, *str, args);
	// else if (*str == 's' || *str == 'S' || *str == 'c' || *str == 'C')
	// 	print_char_conversion(str, args);
	ft_putstr("unsupported conversion specifier");
	str++;

	// if (*str == 'd' || *str == 'i')
	// {
	// 	int nbr;
	// 	nbr = va_arg(args, int); 
	// 	ft_putnbr(nbr);
	// 	str++;
	// }
	// if (*str == 'o')
	// {
	// 	print_unsignedint_to_base(va_arg(args, unsigned int), 8);
	// 	str++;
	// }
	// if (*str == 'u')
	// {
	// 	print_unsignedint_to_base(va_arg(args, unsigned int), 10);
	// 	str++;
	// }
	// if (*str == 'x')
	// {
	// 	print_unsignedint_to_base(va_arg(args, unsigned int), 16);
	// 	str++;
	// }
	// if (*str == 'X')
	// {
	// 	print_unsignedint_to_base_x(va_arg(args, unsigned int), 16);
	// 	str++;
	// }
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







// void	ft_printf(const char *format, ...)
// {
// 	va_list args; // ap = variable argument list
// 	t_info conver_info;
// 	const char *field_width_str; // do I need to malloc for const char* or not?
// 	const char *precision_str; // do I need to malloc for const char* or not?

// 	int i;
// 	int j;
// 	i = 0;
// 	j = 0;
// 	conver_info.flag = (char*)malloc(sizeof(char)* 1);   // malloc #1
// 	conver_info.length_modifier = (char*)malloc(sizeof(char)* 3);   // malloc #2
// 	// I created a struct using stack memory, inside the struct I have a char *str, do I need to melloc memory for the string in the heap?
// 	// my printf told me, yes, otherwise, seg fault or bus error.
// 	// but I only malloced 1 char, who can explain why I don't need to melloc the whole length of the string?

// 	va_start(args, format);	
// 	while(*format != '\0')
// 	{

// 		while ((*format != '%') && (*format != '\0'))
// 		{
// 			ft_putchar(*format);
// 			format++;
// 		}
// 		// ft_putchar('B');
// 		if (*format == '%')   // use strslpit to separate all %....conversion modifier string!  later............
// 			format++;

// 		conver_info.pstr = format;
// 		// get flag info (struct)		
// 		get_flag_info(&conver_info);

// while (*str == '#' || *str == '-' || *str == '+' || *str == ' ' || *str == '0') 
// 	{
// 		conver_info.flag[i] = *str;
// 		i++;
// 		format++;
// 	}




// 		// if field width is negative ignore
// 		// get field width (int)
// 		while (*format >= '1' && *format <= '9')
// 		{
// 			field_width_str = (const char*)format;
// 			conver_info.field_width = ft_atoi(field_width_str);
// 			while (*format >= '1' && *format <= '9')
// 			format++;
// 		}
// 		// ft_putnbr(conver_info.field_width);



// 		// get precision (int)
// 		if(*format == '.')
// 			format++;
// 		while (*format >= '1' && *format <= '9')
// 		{
// 			precision_str = (const char*)format;
// 			conver_info.precision = ft_atoi(precision_str);
// 			while (*format >= '1' && *format <= '9')
// 			format++;
// 		}
// 		// ft_putnbr(ft_atoi(precision_str));
// 		// ft_putnbr(conver_info.precision);


// 		// get length modifier string, hh/h/l/ll/j/z
// 		while (*format == 'h' || *format == 'l' || *format == 'j' || *format == 'z') 
// 		{
// 			conver_info.length_modifier[j] = *format;
// 			j++;
// 			format++;
// 		}
// 		conver_info.length_modifier[j] = '\0';
// 		// ft_putstr(conver_info.length_modifier);
// 		// get length modifer info (struct)
// 		get_len_mod_info(&conver_info);

// 		// ft_putchar('b');
// 		// conversion specifier
// 		if (*format == 'd' || *format == 'i')
// 		{
// 			int nbr;
// 			nbr = va_arg(args, int);   // need to test the ld, lld, hh, h, j, z form here ................
// 			// need to figour out == == ........ ????
// 			if (ft_nbrlen(nbr) > conver_info.field_width && ft_nbrlen(nbr) > conver_info.precision)
// 				print_way_1(&conver_info, nbr); // it dosen't matter when precision>field_width or precision<field_width
// 			else if (conver_info.field_width > ft_nbrlen(nbr) && ft_nbrlen(nbr) > conver_info.precision)
// 				print_way_2(&conver_info, nbr);
// 			else if (conver_info.field_width > conver_info.precision && conver_info.precision > ft_nbrlen(nbr))
// 				print_way_3(&conver_info, nbr);
// 			else if (conver_info.precision > conver_info.field_width && conver_info.precision > ft_nbrlen(nbr))
// 				print_way_4(&conver_info, nbr); // it dosen't matter when field_width > nbrlen or field_width < nbrlen
// 			else // ???
// 			{
// 				ft_putstr("more conditions needed");
// 			}
// 			// if (ft_nbrlen(nbr) == conver_info.precision && ft_nbrlen(nbr) == conver_info.field_width)
// 			// 	ft_putnbr(nbr);

// 			// printf("%d\n", ft_nbrlen(nbr));
			
// 			format++;
// 		}
// 		if (*format == 'o')
// 		{
// 			print_unsignedint_to_base(va_arg(args, unsigned int), 8);
// 			format++;
// 		}
// 		if (*format == 'u')
// 		{
// 			print_unsignedint_to_base(va_arg(args, unsigned int), 10);
// 			format++;
// 		}
// 		if (*format == 'x')
// 		{
// 			print_unsignedint_to_base(va_arg(args, unsigned int), 16);
// 			format++;
// 		}
// 		if (*format == 'X')
// 		{
// 			print_unsignedint_to_base_x(va_arg(args, unsigned int), 16);
// 			format++;
// 		}
// 	}
// 	va_end(args);
// }
