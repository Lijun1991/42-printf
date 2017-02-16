#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <locale.h>

static void	ft_part_one(void)
{
	printf("%d\n", ft_printf("Bla bla % d", 0));

	ft_printf("{27}%%d{0} (42) : \t");
	ft_printf("\t%d\t", 42);
	printf("\t\t%d\n", 42);
	
	ft_printf("{33}%%i{0} (-42) : \t");
	ft_printf("\t%i\t", -42);
	printf("\t\t%i\n", -42);
	
	ft_printf("{39}%%o{0} (42) : \t");
	ft_printf("\t%o\t", 42);
	printf("\t\t%o\n", 42);
	
	ft_printf("{51}%%O{0} (LONG_MAX) : \t");
	ft_printf("%O\t", LONG_MAX);
	printf("%lO\n", LONG_MAX);
	
	ft_printf("{63}%%x{0} (42) : \t");
	ft_printf("\t%x\t", 42);
	printf("\t\t%x\n", 42);
	
	ft_printf("{75}%%X{0} (42) : \t");
	ft_printf("\t%X\t", 42);
	printf("\t\t%X\n", 42);
	
	ft_printf("{81}%%u{0} (ULONG_MAX / 2) :\t");
	ft_printf("%u\t", ULONG_MAX / 2);
	printf("\t%lu\n", ULONG_MAX / 2);
	
	ft_printf("{99}%%U{0} (ULONG_MAX / 2) :\t");
	ft_printf("%U\t", ULONG_MAX / 2);
	printf("%lU\n", ULONG_MAX / 2);
}

static void	ft_part_two(void)
{
	ft_printf("{99}%%U{0} (ULONG_MAX / 2) :\t");
	ft_printf("%U\t", ULONG_MAX / 2);
	printf("%lU\n", ULONG_MAX / 2);
	
	ft_printf("{105}%%x{0} (42) : \t");
	ft_printf("\t%x\t", 42);
	printf("\t\t%x\n", 42);
	
	ft_printf("{117}%%f{0} (-1.42) : \t");
	ft_printf("\t%f\t", -1.42);
	printf("\t%f\n", -1.42);
	
	ft_printf("{123}%%F{0} (14445.64242) : \t");
	ft_printf("%F\t", 14445.64242);
	printf("\t%F\n", 14445.64242);
	
	// ft_printf("{135}%%b{0} (42) : \t");
	// ft_printf("\t%b\n", 42);
	// ft_printf("{147}%%B{0} (◼) : \t");
	// ft_printf("\t%B\n", 9724);
	
	ft_printf("{153}%%c{0} (a) : \t");
	ft_printf("\t%c\t", 'a');
	printf("\t\t%c\n", 'a');
	
	ft_printf("{171}%%p{0} (ft_printf) : \t");
	ft_printf("%p\t", ft_printf);
	printf("\t%p\n", ft_printf);
	
	ft_printf("{183}%%C{0} (✔) : \t");
	ft_printf("\t%C\t", 10004);
	printf("\t\t%C\n", L'✔');
}

static void	ft_part_three(void)
{
	ft_printf("{171}%%p{0} (ft_printf) : \t");
	ft_printf("%p\t", ft_printf);
	printf("\t%p\n", ft_printf);
	
	ft_printf("{183}%%C{0} (✔) : \t");
	ft_printf("\t%C\t", 10004);
	printf("\t\t%C\n", L'✔');
	
	ft_printf("{195}%%s{0} (Hello World!) : \t");
	ft_printf("%s\t", "Hello World!");
	printf("\t%s\n", "Hello World!");
	
	ft_printf("{207}%%S{0} (我是一只猫。) : \t");
	ft_printf("%S\t", L"我是一只猫。");
	printf("\t%S\n", L"我是一只猫。");
}

int			main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	ft_printf("{156}SRC{0}\t\t\t{38}MINE{0}\t\t\t{208}ORIGINAL{0}\n");
	ft_part_one();
	ft_part_two();
	ft_part_three();
	ft_printf("\nSupport flags & modifiers : l, ll, h, hh, j, z, *, !, ., #, 0,\
 -, + and space\n");
	ft_putstr("\n--ft_printf(\"{A}\")------------------------------------------\
--------\n");
	ft_printf("{A}");
	return (0);
}
