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
