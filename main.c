#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a = 32;
    int b = 32;
    int c = 32;
    int d = 32;
    char *str = "adana";
    int len = ft_printf("%s\n", str);
    ft_printf("%d\n", len);
    int len2 = printf("%s\n", str);
    printf("%d\n", len2);
    ft_printf("a:%p\nb:%p\nc:%p\nd:%p\n", &a, &b, &c, &d);
    ft_printf("Hello %s! Your number is %d and hex is %x.\n", "World", 42, 255);
    ft_printf("Unsigned number: %u, Pointer: %p, Percent sign: %%\n", 12345, &a);
    ft_printf("Character: %c, String: %s\n", 'A', "Hello, 42istanbul!");
    ft_printf("Hexadecimal (lowercase): %x, Hexadecimal (uppercase): %X\n", 255, 255);
    ft_printf("Negative number: %d\n", -42);

    return 0;
}
