/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:25:18 by lwang             #+#    #+#             */
/*   Updated: 2017/03/18 21:25:23 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

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