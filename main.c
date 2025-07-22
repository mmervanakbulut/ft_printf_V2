#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Your number is %d and hex is %x.\n", "World", 42, 255);
    ft_printf("Unsigned number: %u, Pointer: %p, Percent sign: %%\n", 12345, (void *)0x7ffeefbff5c0);
    ft_printf("Character: %c, String: %s\n", 'A', "Hello, 42istanbul!");
    ft_printf("Hexadecimal (lowercase): %x, Hexadecimal (uppercase): %X\n", 255, 255);
    ft_printf("Negative number: %d\n", -42);

    return 0;
}
