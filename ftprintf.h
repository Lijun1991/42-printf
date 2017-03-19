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
#include "./libft/libft.h"

typedef struct	s_info
{
	char flag;
	int *field_width;
	int *precision;
	char *length_modifier;
	char conversion_specifier;
}				t_info;

void	ft_printf(const char *format, ...);

void    print_unsignedint_to_base(unsigned int nbr, unsigned int base);
void    print_unsignedint_to_base_x(unsigned int nbr, unsigned int base);


#endif