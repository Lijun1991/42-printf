/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:28:17 by lwang             #+#    #+#             */
/*   Updated: 2017/03/27 18:28:41 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	print_wchar(t_info *conver_info, char *str, int j, int sign)
{
	int i;

	if (sign == 1)
	{
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
	else
		write(1, str, j);
}

void	print_regular_char(t_info *conver_info, char chara, int sign) // sign to print for char or string
{
	int i;
	
	if (sign == 1)
	{
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
	else
		ft_putchar(chara);
}

void	print_wide_char(t_info *conver_info, wchar_t wchara, int sign)
{
	char str[4];

	if (wchara <= 0x7F)
		print_regular_char(conver_info, wchara, sign);
	else if (wchara <= 0x7FF)
	{
		str[0] = (((wchara & 0x07c0) >> 6) + 0xc0);   // ???? why 0x07c0????? and why + 0xc0???
		str[1] = ((wchara & 0x03F0) + 0x80);
		print_wchar(conver_info, str, 2, sign);
	}
	else if (wchara <= 0xFFFF)
	{
		str[0] = (((wchara & 0xF000) >> 12) + 0xE0);
		str[1] = (((wchara & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wchara & 0x003F) + 0x80);
		print_wchar(conver_info, str, 3, sign);
	}
	else if (wchara <= 0x10FFFF)
	{
		str[0] = (((wchara & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wchara & 0x03F000) >> 12) + 0x80);
		str[2] = (((wchara & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wchara & 0x003F) + 0x80);
		print_wchar(conver_info, str, 4, sign);
	}
}

void	print_char(t_info *conver_info, va_list args, int sign)
{
	char chara;
	wchar_t wchara;

	if (ft_strncmp(conver_info->len_mod, "l", 1) == 0)
	{
		wchara = va_arg(args, wint_t);
		print_wide_char(conver_info, wchara, sign);
	}
	else
	{
		chara = (unsigned char)va_arg(args, int);
		print_regular_char(conver_info, chara, sign);
	}
}

void	print_char_conversion(t_info *conver_info, char c, va_list args)
{
	char chara;
	int sign;

	if (c == 'C' || c == 'S')
	{
		strcpy(conver_info->len_mod, "l");
		conver_info->conversion_specifier = ft_tolower(c);
	}
	if (conver_info->conversion_specifier == 'c')
	{
		sign = 1;
		print_char(conver_info, args, sign);
	}
	if (conver_info->conversion_specifier == 's')
	{
		sign = 0;
		print_string(conver_info, args, sign);
	}
}
