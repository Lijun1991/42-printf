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

int main(void)
{
    // 4294967295
    unsigned int d = 4294967295;
    // ft_unsignedint_to_hexa(d);
    // ft_print_unsigned_int(d);
    print_unsignedint_to_base_x(d, 16);
    return 0;
}