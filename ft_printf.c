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


void	ft_printf(const char *format, ...)
{
	va_list args; // ap = variable argument list
	t_info	*conver_info;

	conver_info = (t_info*)malloc(sizeof(t_info) * 1);

	va_start(args, format);
	while(*format != '\0')
	{
		while ((*format != '%') && (*format != '\0'))
		{
			ft_putchar(*format);
			format++;
		}
		if (*format == '%')
			format++;
		// get_conversion_info(format);
		if (*format == '-')
		{
			conver_info
		}
		if (*format == 'd' || *format == 'i')
		{
			ft_putnbr(va_arg(args, int));
			format++;
		}
		if (*format == 'o')
		{
			print_unsignedint_to_base(va_arg(args, unsigned int), 8);
			format++;
		}
		if (*format == 'u')
		{
			print_unsignedint_to_base(va_arg(args, unsigned int), 10);
			format++;
		}
		if (*format == 'x')
		{
			print_unsignedint_to_base(va_arg(args, unsigned int), 16);
			format++;
		}
		if (*format == 'X')
		{
			print_unsignedint_to_base_x(va_arg(args, unsigned int), 16);
			format++;
		}
	}
	va_end(args);
}
