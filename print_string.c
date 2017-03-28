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

int	ft_wstrlen(wchar_t *tmp)
{
	int len;

	len = 0;
	while (*tmp != '\0')
	{
		if (*tmp <= 0x7F)
			len += 1;
		else if (*tmp <= 0x7FF)
			len += 2;
		else if (*tmp <= 0xFFFF)
			len += 3;
		else if (*tmp <= 0x10FFFF)
			len += 4;
		tmp++;
	}
	return (len);
}

int	get_pre(wchar_t *ws, int precision)
{
	wchar_t *tmp = ws;

	while (*tmp != '\0')
	{
		if (*tmp <= 0x7F && precision >= 1)
			precision -= 1;
		else if (*tmp <= 0x7FF && precision >= 2)
			precision -= 2;
		else if (*tmp <= 0xFFFF && precision >= 3)
			precision -= 3;
		else if (*tmp <= 0x10FFFF && precision >= 4)
			precision -= 4;
		else
			break;
		tmp++;
	}
	return (precision);
}

void	ft_putwstr_len(wchar_t *ws, t_info *conver_info, int precision, int sign)
{
	char str[4];

	while (*ws != '\0')
	{
		if (*ws <= 0x7F && precision >= 1)
		{
			print_regular_char(conver_info, *ws, sign);
			precision -= 1;
		}
		else if (*ws <= 0x7FF && precision >= 2)
		{
			str[0] = (((*ws & 0x07c0) >> 6) + 0xc0);
			str[1] = ((*ws & 0x03F0) + 0x80);
			print_wchar(conver_info, str, 2, sign);
			precision -= 2;
		}
		else if (*ws <= 0xFFFF && precision >= 3)
		{
			str[0] = (((*ws & 0xF000) >> 12) + 0xE0);
			str[1] = (((*ws & 0x0Fc0) >> 6) + 0x80);
			str[2] = ((*ws & 0x003F) + 0x80);
			print_wchar(conver_info, str, 3, sign);
			precision -= 3;
		}
		else if (*ws <= 0x10FFFF && precision >= 4)
		{
			ft_putnbr(precision);
			str[0] = (((*ws & 0x1c0000) >> 18) + 0xF0);
			str[1] = (((*ws & 0x03F000) >> 12) + 0x80);
			str[2] = (((*ws & 0x0Fc0) >> 6) + 0x80);	
			str[3] = ((*ws & 0x003F) + 0x80);
			print_wchar(conver_info, str, 4, sign);
			precision -= 4;
		}
		else
			break;
		ws++;
	}
}

void	print_w_str_precision(t_info *conver_info, wchar_t *ws, int len, int sign)
{
	int i;
	int j;
	int pre;

	if (conver_info->precision >= len)
	{
		i = conver_info->field_width - (len - get_pre(ws, conver_info->precision));
		if (conver_info->flag_info->minus == '-')
		{
			while (*ws != '\0')
			{
				print_wide_char(conver_info, *ws, sign);
				ws++;
			}
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
			while (*ws != '\0')
			{
				print_wide_char(conver_info, *ws, sign);
				ws++;
			}
		}
	}
	else
	{
		i = conver_info->field_width - (conver_info->precision - get_pre(ws, conver_info->precision));
		if (conver_info->flag_info->minus == '-')
		{
			ft_putwstr_len(ws, conver_info, conver_info->precision, sign);
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
			ft_putwstr_len(ws, conver_info, conver_info->precision, sign);
		}
	}
}

void	print_w_string(t_info *conver_info, wchar_t *ws, int len, int sign)
{
	int i;

	i = conver_info->field_width - len;
	if (conver_info->precision == 1)
	{
		if (conver_info->flag_info->minus == '-')
		{
			while (*ws != '\0')
			{
				print_wide_char(conver_info, *ws, sign);
				ws++;
			}
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
			while (*ws != '\0')
			{
				print_wide_char(conver_info, *ws, sign);
				ws++;
			}
		}
	}
	else
		print_w_str_precision(conver_info, ws, len, sign);
}

void	print_wide_string(t_info *conver_info, wchar_t *ws, int sign)
{
	wchar_t *tmp;
	int len;

	tmp = ws;
	len = ft_wstrlen(tmp);
	print_w_string(conver_info, ws, len, sign);
}



void	ft_putstr_len(char *s, int i)
{
	while (i > 0 && i < ft_strlen(s))
	{
		ft_putchar(*s);
		i--;
		s++;
	}
}

void	print_reg_str_precision(t_info *conver_info, char *s)
{
	int i;
	int j;

	i = conver_info->field_width - ft_strlen(s);
	if (conver_info->precision >= ft_strlen(s))
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
	{
		j = conver_info->field_width - conver_info->precision;
		if (conver_info->flag_info->minus == '-')
		{
			ft_putstr_len(s, conver_info->precision);
			while (i-- > 0)
				ft_putchar(' ');
		}
		else
		{
			while (j-- > 0)
				{
					if (conver_info->flag_info->zero == 'y')
						ft_putchar('0');
					else
						ft_putchar(' ');
				}
			ft_putstr_len(s, conver_info->precision);
		}
	}
}

void	print_reg_string(t_info *conver_info, char *s)
{
	int i;

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

void	print_string(t_info *conver_info, va_list args, int sign)
{
	char *s;
	wchar_t *ws;

	if (ft_strncmp(conver_info->len_mod, "l", 1) == 0)
	{
		ws = va_arg(args, wchar_t*);
		print_wide_string(conver_info, ws, sign);
	}
	else
	{
		s = va_arg(args, char*);
		print_reg_string(conver_info, s);
	}
}
