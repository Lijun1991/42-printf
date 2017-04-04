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

void	print_str(char *str, t_info *conver_info)
{
	 //printf("\n%d, %d, %d, %d, %d\n", conver_info->iszero, conver_info->is_nopre, conver_info->is_dot, conver_info->is_dot_zero, conver_info->is_dot_pre);
	// //%d
	if (conver_info->iszero == 1 && conver_info->is_nopre == 1 && conver_info->is_dot == 1 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 0)
	{
		if (ft_strchr("xXdou", conver_info->conversion_specifier))
		{
			conver_info->count += pputchar('0');
		}	
	}
	//%.d
	if (conver_info->iszero == 1 && conver_info->is_nopre == 0 && conver_info->is_dot == 1 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 0)
	{
		if (conver_info->conversion_specifier == 'o' && conver_info->flag_info->hash == '#')
		{
			conver_info->count += pputchar('0');
		}	
	}
	//%.0d
	if (conver_info->iszero == 1 && conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 1 && conver_info->is_dot_pre == 0)
	{
		if (conver_info->conversion_specifier == 'o' && conver_info->flag_info->hash == '#')
		{
			// ft_putstr("hello");
			// if (conver_info->sign)
				conver_info->count += pputchar('0');
		}	
	}
	//%.5d
	if (conver_info->iszero == 1 && conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 1)
	{
		if (ft_strchr("xXod", conver_info->conversion_specifier))
		{
			
			conver_info->count += pputchar('0');
		}	
	}
	//#.2o, 42
	if (conver_info->iszero == 0 && conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 1)
	{
		if (ft_strchr("o", conver_info->conversion_specifier) && conver_info->flag_info->hash == '#')
		{
			// ft_putstr("hello");
			 // if (conver_info->sign)
				conver_info->count += pputchar('0');
		}	
	}
	//
	if (conver_info->iszero == 0 && conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 1 && conver_info->is_dot_pre == 0)
	{
		if (ft_strchr("o", conver_info->conversion_specifier) && conver_info->flag_info->hash == '#')
		{
			conver_info->count += pputchar('0');
		}	
	}
	if (conver_info->iszero == 0 && conver_info->is_nopre == 1 && conver_info->is_dot == 1 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 0)
	{
		if (ft_strchr("o", conver_info->conversion_specifier) && conver_info->flag_info->hash == '#')
		{
			conver_info->count += pputchar('0');
		}	
	}
	if (conver_info->iszero == 0 && conver_info->is_nopre == 0 && conver_info->is_dot == 1 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 0)
	{
		if (ft_strchr("o", conver_info->conversion_specifier) && conver_info->flag_info->hash == '#')
		{
			conver_info->count += pputchar('0');
		}	
	}

	while(*str != '\0' && *str == '*')
		str++;
	while (*str != '\0' && *str != '*')
	{
		conver_info->count += pputchar(*str);
		str++;
	}
}

void	print_no_precision(t_info *conver_info, char *str, int len)
{
	int i;

	i = 0;

	//printf("%d %d %d\n", len, conver_info->sign, conver_info->field_width);
	if (conver_info->precision == -1)
	{
		if (len + conver_info->sign >= conver_info->field_width)
		{
			//ft_putstr("hello");
			conver_info->count += pputstr(conver_info->pre_sign);
			print_str(str, conver_info);
		}
		else
		{
			i = conver_info->field_width - len - conver_info->sign;
			if (conver_info->flag_info->zero == 'y')
			{
				conver_info->count += pputstr(conver_info->pre_sign);
				while (i-- > 0) 
					conver_info->count += pputchar('0');
			}
			else
			{
				
				// ft_putnbr(len);
				while (i-- > 0) 
					conver_info->count += pputchar(' ');
				conver_info->count += pputstr(conver_info->pre_sign);
			}
			print_str(str, conver_info);
		}
	}
}

void	print_exit_precision(t_info *conver_info, char *str, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;

	//printf("\n%d %d %d\n", len, conver_info->sign, conver_info->field_width);
	if (conver_info->precision != -1)
	{
		if (len >= conver_info->precision)
		{
			if (conver_info->precision + conver_info->sign >= conver_info->field_width)
			{

				conver_info->count += pputstr(conver_info->pre_sign);
				print_str(str, conver_info);
			}
			else
			{
				// ft_putstr("hello");
				i = conver_info->field_width - len - conver_info->sign;
				if (conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 1)
				{

					if (ft_strchr("o", conver_info->conversion_specifier) && conver_info->flag_info->hash == '#')
					{
						i--;
					}	
				}
				if (conver_info->star == '*' && conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 1 && conver_info->is_dot_pre == 0)
				{
					// ft_putstr("hello");
					if (conver_info->flag_info->zero == 'y')
						print_nbr_helper(conver_info, i, '0');
					else
						print_nbr_helper(conver_info, i, ' ');
				}
				else
					print_nbr_helper(conver_info, i, ' ');
				conver_info->count += pputstr(conver_info->pre_sign);
				print_str(str, conver_info);
			}
		}
		else
		{
			if (conver_info->precision + conver_info->sign >= conver_info->field_width)
			{

				j = conver_info->precision - len; // -len;
				// ft_putnbr(j);
				// ft_putstr("hello");
				// if (sign).............
				if (conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 1)
				{

					if (ft_strchr("o", conver_info->conversion_specifier) && conver_info->flag_info->hash == '#')
					{
						j--;
					}	
				}

				conver_info->count += pputstr(conver_info->pre_sign);
				print_nbr_helper(conver_info, j, '0');
				print_str(str, conver_info);
			}
			else
			{
				i = conver_info->field_width - conver_info->precision - conver_info->sign;

				// if (conver_info->iszero == 0 && conver_info->is_nopre == 0 && conver_info->is_dot == 0 && conver_info->is_dot_zero == 0 && conver_info->is_dot_pre == 1)
				// {
				// 	if (ft_strchr("o", conver_info->conversion_specifier) && conver_info->flag_info->hash == '#')
				// 	{
				// 		i--;
				// 	}	
				// }
				print_nbr_helper(conver_info, i, ' ');
				conver_info->count += pputstr(conver_info->pre_sign);
				j = conver_info->precision - len;
				print_nbr_helper(conver_info, j, '0');
				print_str(str, conver_info);	
			}
		}
	}
}

void	print_no_precision_left(t_info *conver_info, char *str, int len)
{
	int i;

	i = 0;
	if (conver_info->precision == -1)
	{
		if (len + conver_info->sign >= conver_info->field_width)
		{
			conver_info->count += pputstr(conver_info->pre_sign);
			print_str(str, conver_info);
		}
		else
		{
			i = conver_info->field_width - len - conver_info->sign;
			conver_info->count += pputstr(conver_info->pre_sign);
			print_str(str, conver_info);
			print_nbr_helper(conver_info, i, ' ');
		}
	}
}

void	print_exit_precision_left(t_info *conver_info, char *str, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (conver_info->precision != -1)
	{
		if (len >= conver_info->precision)
		{
			if (conver_info->precision + conver_info->sign >= conver_info->field_width)
			{
				conver_info->count += pputstr(conver_info->pre_sign);
				print_str(str, conver_info);
			}
			else
			{
				i = conver_info->field_width - len - conver_info->sign;
				conver_info->count += pputstr(conver_info->pre_sign);
				print_str(str, conver_info);
				print_nbr_helper(conver_info, i, ' ');
			}
		}
		else
		{
			if (conver_info->precision + conver_info->sign >= conver_info->field_width)
			{
				j = conver_info->precision - len;
				conver_info->count += pputstr(conver_info->pre_sign);
				print_nbr_helper(conver_info, j, '0');
				print_str(str, conver_info);
			}
			else
			{
				j = conver_info->precision - len;
				conver_info->count += pputstr(conver_info->pre_sign);
				print_nbr_helper(conver_info, j, '0');
				print_str(str, conver_info);
				i = conver_info->field_width - conver_info->precision - conver_info->sign;
				print_nbr_helper(conver_info, i, ' ');
			}
		}
	}
}

void	print_nbr_helper(t_info *conver_info, int i, char c)
{
	// if (conver_info->iszero = 1 && conver_info->conversion_specifier == 'o' && )
	while (i-- > 0)
		conver_info->count += pputchar(c);
}

void	print_nbr(t_info *conver_info, char *str, int len)
{
	
	// ft_putchar(conver_info->flag_info->minus);
	if (conver_info->flag_info->minus != '-')
	{

		print_no_precision(conver_info, str, len);
		print_exit_precision(conver_info, str, len);
	}
	else
	{

		print_no_precision_left(conver_info, str, len);
		print_exit_precision_left(conver_info, str, len);
	}
}
