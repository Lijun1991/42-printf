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

#ifndef FTPRINTF_H
# define FTPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <locale.h>
#include <wchar.h>
#include "./libft/libft.h"

typedef struct	s_flag
{
	char hash;
	char minus;
	char plus;
	char space;
	char zero;
}				t_flag;

// typedef struct	s_len_m // short for length modifier
// {
// 	char signed_un_char[2]; //hh
// 	char short_int; //h
// 	char long_int; //l
// 	char long_long_int[2]; //ll
// 	char intmax;
// 	char sizet;
// }				t_len_m;

typedef struct	s_info
{
	// char *pstr; // the string after percentage;
	// char *flag;
	int	field_width; 
	int	precision;
	// char length_modifier;  // diouxX csCS
	char conversion_specifier;
	t_flag *flag_info;
	// t_len_m *len_mod_info;
	char len_mod[3];
	char pre_sign[3];
}				t_info;

void	ft_printf(char *format, ...);

void    print_unsignedint_to_base(unsigned int nbr, unsigned int base);
void    print_unsignedint_to_base_x(unsigned int nbr, unsigned int base);


#endif