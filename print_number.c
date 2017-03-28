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

#include "ftprintf.h"

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
		nbr = number_to_print_signed(conver_info, args); 
	else
		nbr = number_to_print_unsigned(conver_info, args);

	if (conver_info->conversion_specifier == 'd' || conver_info->conversion_specifier == 'u')
		print_result(nbr, conver_info, 10);
	else if (conver_info->conversion_specifier == 'o')
		print_result(nbr, conver_info, 8);
	else if (conver_info->conversion_specifier == 'x')
		print_result(nbr, conver_info, 16);
	else if (conver_info->conversion_specifier == 'X')
		print_result_capx(nbr, conver_info, 16);
}
