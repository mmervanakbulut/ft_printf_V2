# ft_printf

A custom implementation of the printf function in C, recreating the behavior of the standard library's printf with support for various format specifiers.

## Description

This project implements a custom `ft_printf` function that mimics the behavior of the standard `printf` function. It handles multiple format specifiers and returns the number of characters printed.

## Supported Format Specifiers

| Specifier   | Description              |
| ----------- | ------------------------ |
| `%c`        | Single character         |
| `%s`        | String                   |
| `%d` / `%i` | Signed decimal integer   |
| `%u`        | Unsigned decimal integer |
| `%x`        | Hexadecimal (lowercase)  |
| `%X`        | Hexadecimal (uppercase)  |
| `%p`        | Pointer address          |
| `%%`        | Literal percent sign     |

## Files Structure

- [`ft_printf.c`](ft_printf.c) - Main printf function implementation
- [`ft_printf.h`](ft_printf.h) - Header file with function declarations
- [`ft_handle_format.c`](ft_handle_format.c) - Format specifier handler
- [`ft_print_chars.c`](ft_print_chars.c) - Character and string printing functions
- [`ft_print_numbers.c`](ft_print_numbers.c) - Number printing functions (decimal, unsigned, hex)
- [`ft_print_pointer.c`](ft_print_pointer.c) - Pointer printing functions
- [`main.c`](main.c) - Test file with examples
- [`Makefile`](Makefile) - Build configuration

## Compilation

To compile the library:

```bash
make
```

To compile and run with the test main:

```bash
make compile
```

## Usage

Include the header and use [`ft_printf`](ft_printf.c) just like the standard printf:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "World", 42);
    return 0;
}
```

## Key Features

- Handles null pointers safely (prints "(null)" for strings, "0x0" for pointers)
- Recursive implementation for number printing
- Memory-efficient with no dynamic allocation
- Returns the total number of characters printed
- Supports both lowercase and uppercase hexadecimal output

This implementation follows the 42 school coding standards and successfully handles all
