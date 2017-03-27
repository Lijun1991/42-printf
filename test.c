#include <stdio.h>
#include "./libft/libft.h"
#include "ftprintf.h"

// void    print_unsignedint_to_base_x(unsigned int nbr, unsigned int base)
// {
//     const char tab[] = "0123456789ABCDEF";

//     if (nbr < base )
//         ft_putchar(tab[nbr]);
//     else if (nbr >= base && nbr <= 4294967295)
//     {
//         print_unsignedint_to_base(nbr / base, base);
//         ft_putchar(tab[nbr % base]);
//     }
// }

// void    print_unsignedint_to_base(unsigned int nbr, unsigned int base)
// {
//     const char tab[] = "0123456789abcdef";

//     if (nbr < base )
//         ft_putchar(tab[nbr]);
//     else if (nbr >= base && nbr <= 4294967295)
//     {
//         print_unsignedint_to_base(nbr / base, base);
//         ft_putchar(tab[nbr % base]);
//     }
// }

// void   ft_unsignedint_to_hexa(unsigned int nbr)
// {
//     const char tab[] = "0123456789abcdef";

//     if (nbr == 0)
//         ft_putchar('0');
//     else if (nbr < 16 && nbr > 0)
//         ft_putchar(tab[nbr]);
//     else
//     {
//         ft_unsignedint_to_hexa(nbr / 16);
//         ft_putchar(tab[nbr % 16]);
//     }
// }

            // if (ft_nbrlen(nbr) >= conver_info.field_width && ft_nbrlen(nbr) >= conver_info.precision)
            // {
            //     if (conver_info.flag_info.hash == '#' && conver_info.flag_info.minus == '-' && conver_info.flag_info.plus == '+' && conver_info.flag_info.space == ' ' && conver_info.flag_info.zero == '0')
            //         ft_putchar('+');
            //     if (conver_info.flag_info.hash == 'n' && conver_info.flag_info.minus == '-' && conver_info.flag_info.plus == '+' && conver_info.flag_info.space == ' ' && conver_info.flag_info.zero == '0')
            //         ft_putchar('+');
            //     if (conver_info.flag_info.hash == 'n' && conver_info.flag_info.minus == 'n' && conver_info.flag_info.plus == '+' && conver_info.flag_info.space == ' ' && conver_info.flag_info.zero == '0')
            //         ft_putchar('+');
            //     if (conver_info.flag_info.hash == 'n' && conver_info.flag_info.minus == 'n' && conver_info.flag_info.plus == 'n' && conver_info.flag_info.space == ' ' && conver_info.flag_info.zero == '0')
            //         ft_putchar(' ');
            //     // if (conver_info.flag_info.hash == 'n' && conver_info.flag_info.minus == 'n' && conver_info.flag_info.plus == 'n' && conver_info.flag_info.space == 'n' && conver_info.flag_info.zero == '0')
            //     //  do nothing;
            //     // if (conver_info.flag_info.hash == 'n' && conver_info.flag_info.minus == 'n' && conver_info.flag_info.plus == 'n' && conver_info.flag_info.space == 'n' && conver_info.flag_info.zero == 'n')
            //     //  do nothing;
            //     ft_putnbr(nbr);
            // }


static int      ft_abs(int nb)
{
    if (nb < 0)
        nb = -nb;
    return (nb);
}

char    *ft_itoa_base(unsigned int value, int base)
{
    char    *str;
    int     size;
    char    *tab;
    int     flag;
    int     tmp;
    flag = 0;
    size = 0;
    tab = "0123456789ABCDEF";
    if (base < 2 || base > 16)
        return (0);
    if (base == 10)
        flag = 1;
    tmp = value;
    while (tmp /= base)
        size++;
    size = size + flag + 1;
    str = (char *)malloc(sizeof(char) * size  + 1);
    str[size] = '\0';
    if (flag == 1)
        str[0] = '-';
    while (size > flag)
    {
        str[size - 1] = tab[ft_abs(value % base)];
        size--;
        value /=base;
    }
    return (str);
}

int main(void)
{
    // unsigned int d = 4294967295;
    // int i = 1225555;
    ft_putstr(ft_itoa_base(4294967295, 10));
    return 0;
}