/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:57:16 by lwang             #+#    #+#             */
/*   Updated: 2017/03/16 19:40:43 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");

	// diouxX // the int argument is converted to
	int signed_decimal_di = -5; // convert int to 10 base signed decimal
	int unsigned_octal_o = 500; // convert int 500 to 8 base unsiged octal 764
   								// 764(8 base) = 7x8*2 + 6x8*1 + 4x8*0 = 500(10 base)	
	int unsigned_decimal_u = 5;
	int unsigned_hexadecimal_x = 15666; // convert int to unsigned hexadecimal 16 base
										// why can't change this to -15666????
	int unsigned_hexadecimal_X = 14;
	

	// ld lo lu // the long int argument is converted to 
	long int signed_decimal_ld = 2147483647; 	
	long int unsigned_octal_lo = 22255;
	long int unsigned_decimal_lu = 2555;

	
	// c C=lc n //the int argument is converted to an unsigned char, and the resulting character is written
	int convert_int_to_unsigned_char = 40;
	int convert_int_to_unsigned_char_lc = 10084;
	char *s = (char*)malloc(sizeof(char) * 6);
	s = "Hello";
	char *ws = (char*)malloc(sizeof(char) * 4);
	ws = "❤❤❤";


	//the void* pointer argument is printed in hexadecimal, to print % sign
	void *v = (void*)malloc(sizeof(void)* 6);
	v = "HELLO";
	int *count;
	char c = 'A';
	int nbr = 5;


	printf("the signed_decimal_di is %i\nthe unsigned_octal_o is %o\nthe unsigned_decimal_u is %u\nthe unsigned_hexadecimal_x is %x\nthe unsigned_hexadecimal_X is %X\n\n", signed_decimal_di, unsigned_octal_o, unsigned_decimal_u, unsigned_hexadecimal_x, unsigned_hexadecimal_X);

	printf("convert long_int to signed_decimal_ld is %ld\n\n", signed_decimal_ld);

	printf("the int 40 convert to an unsinged char and write the char %c\nthe int %d convert to unsigned_char_lc is %lc and unitcode# is %X\n", convert_int_to_unsigned_char, convert_int_to_unsigned_char_lc, convert_int_to_unsigned_char_lc, convert_int_to_unsigned_char_lc);
	printf("the string is %s%n\nthe wide char string is %s\n", s, count, ws); // why not ls but s for wide char???
	printf("%d\n\n", *count);

	printf("the void* is %p\n", v);
	printf("%%\n\n");

	//flags # 0 - + space *
	printf("%d%c\n", nbr, c);
	printf("%#x%c\n", 11, c);
	printf("%0d%c\n", 5, c);
	printf("%-d%c\n", 5, c);
	printf("%+d%c\n", 5, c);
	printf("% d%c\n", 5, c);

	printf("%#*x%c\n", 11, 6, c);
	printf("%0*d%c\n", 5, 6, c);
	printf("%-*d%c\n", 5, 6, c);
	printf("%+*d%c\n", 5, 6, c);
	printf("% *d%c\n", 5, 6, c);

	// printf("%1$d:%2$.*3$d:%4$.*3$d\n", hour, min, precision, sec);
	return (0);
}



