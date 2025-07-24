#include "ft_printf.h"

int funct(int a, ...)
{
	va_list args;
	int i = 0;
	int total = 0;

	va_start(args, a);

	while (i < a)
	{
		total += va_arg(args, int);
		i++;
	}
	va_end(args);
	return (total);
}


int main()
{
	int result = funct(5, 1,2,3,4,5);
	ft_printf("%i", result);
}