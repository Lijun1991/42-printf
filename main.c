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

#include "ftprintf.h"

int main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");

	// diouxX // the int argument is converted to
	// int a = -5; // convert int to 10 base signed decimal
	// int b = 500; // convert int 500 to 8 base unsiged octal 764
 //   								// 764(8 base) = 7x8*2 + 6x8*1 + 4x8*0 = 500(10 base)	
	// int cc = 5;
	// int d = 15666; // convert int to unsigned hexadecimal 16 base
										// why can't change this to -15666????
	long long int e = 2147483647;
	// char c = 'a';
	
	// printf("the int is %#X\n", e);
	// ft_printf("the int is %X\n", e);
	// printf("the int is %02d\n", e);


	printf("the int is %--12.15lldhaha\n", e);
	printf("the int is %-5.3lldhaha\n", e);


// 	// ld /lo lu // the long int argument is converted to 
// 	long int f = 2147483647; 	
// 	long int g = 22255;
// 	long int h = 2555;

	
// 	// c C=lc n s S=ls//the int argument is converted to an unsigned char, and the resulting character is written
// 	int i = 40;
// 	int j = 10084;
// 	char *s = (char*)malloc(sizeof(char) * 6);
// 	s = "Hello";
// 	char *ws = (char*)malloc(sizeof(char) * 4);
// 	ws = "❤❤❤";


// 	//the void* pointer argument is printed in hexadecimal, to print % sign
// 	void *v = (void*)malloc(sizeof(void)* 6);
// 	v = "HELLO";
// 	int *count = (int*)malloc(sizeof(int)*1);
// 	char c = 'A';
// 	short nbr = 5;



// 	printf("convert int %d to signed decimal (di) is %i\nconvert int %d to unsigned octal(o) \
// is %o\nconvert int %d to unsigned decimal(u) is %u\nconvert int %d to unsigned hexadecimal(x) \
// is %x\nconvert %d to unsigned hexadecimal(X) is %X\n\n", a, a, b, b, cc, cc, d, d, e, e);

// 	printf("convert long int %ld to signed_decimal_ld is %ld\nconvert long int %ld to unsigned_octal_lo \
// is %ld\nconvert long int %ld to unsigned_decimal_lu is %ld\n", f, f, g, g, h, h);

// 	printf("the int %d convert to an unsinged char and write the char %c\nthe int %d \
// convert to unsigned_char_lc is %lc and unitcode# is %X\n", i, i, j, j, j);
// 	printf("the string is %s%n\nthe wide char string is %s\n", s, count, ws); // why not ls but s for wide char???
// 	printf("%d\n\n", *count);

// 	printf("the void* is %p\n", v);
// 	printf("%%\n\n");

// 	//flags # 0 - + space *
// 	// printf("%d%c\n", 5, c);
// 	// printf("%#x%c\n", 11, c);

// 	// printf("%0d%c\n", 5, c);
// 	// 	printf("%50d%c\n", 5, c);

// 	// printf("%-5d%c\n", 5, c);
// 	// printf("%+d%c\n", 5, c);
// 	// printf("% 8d%c\n", 5, c);

// 	// printf("%#*x%c\n", 11, 6, c);
// 	// printf("%.*d%c\n", 5, 6, c);
// 	// printf("%-*d%c\n", 5, 6, c);
// 	// printf("%+*d%c\n", 5, 6, c);
// 	// printf("% *d%c\n", 5, 6, c);

// 	// printf("%1$d:%2$.*3$d:%4$.*3$d\n", 9, 8, 7, 2);

// 	printf("Le fichier\e[106m%s{eoc} contient : \e[101m%s{eoc}", s, s);
	return (0);
}



