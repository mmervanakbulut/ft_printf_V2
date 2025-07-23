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

This implementation follows the 42 school coding standards.

# Variadic Functions in C

- A variadic function takes at least one fixed argument an ellipsis(…) as the last parameter.
- The ellipsis (...) in the function parameter list is used to indicate that the function can take a variable number of arguments of any type.
- The types and names of the first N arguments are specified as usual, while the variable number of arguments are accessed using the va_list, va_start, va_arg, and va_end macros.

`return_type name(fixed_arg, ...);`

- This macro initializes the va_list to retrieve arguments from the variable arguments section.

`va_start(list, fixed_arg);`

where,

- list: The va_list to initialize.
- fixed_arg: The last fixed argument before the variable arguments (...).

- This macro returns the next argument from the list. It must be used repeatedly to access all arguments.

`va_arg(list, type);`

- The number of times it should be called should not exceed the number of parameters passed. Due to this, the count of variable arguments passed is also passed as fixed parameters.

where,

- type: The type of the argument to retrieve.

Note: It is important to not mix up the type of the arguments.

- Once all the arguments are processed, use va_end() to clean up the va_list. This ensures that resources associated with va_list are properly released.

`va_end(list);`

## Custom Variadic Functions

- Creating custom variadic functions in C requires the use of four macros: `va_list`, `va_start`, `va_arg`, and `va_end`.
- `va_list` macro is used to declare a variable that will hold the list of arguments passed to the function
- `va_start` macro is used to initialize the va_list variable, and must be passed the last non-variadic argument of the function.

## va_start & va_arg

### va_start(args, last_named_param);

- va_start take args (va_list type) and fixed parameter before the variadic.

```c
int func(int count, ...)
{
	va_list args;
	va_start(args, count)
}
```

- The compiler arranges the arguments in memory (usually on the stack).
- It places the named arguments (`count`) first.
- Then, it places the variadic arguments (`...`) immediately **after** the last fixed argument.
- `va_start(args, count)` tells the program:  
   👉 “Start reading arguments **after** `count`.”
- When you do `va_start(args, count)`, the macro uses `&count` to find the location in memory and then steps forward to find the variadic arguments.
- `va_start(args, last_named_param)` works because arguments are stored in order.

### va_arg(args, type)

- It retrieves the **next argument** from the `va_list` and **automatically advances** the pointer to the next one, based on the size of `type`.

```
int x = va_arg(args, int);
```

Means:

1. “Get the next argument as an `int`.”
2. “Move the internal pointer forward by `sizeof(int)` bytes to get ready for the next one.”

How `va_arg` Works

1. `va_list` (usually implemented as a pointer) keeps track of the **current position** in the argument list.
2. `va_arg`:
   - Dereferences that pointer, casting it to the given `type`
   - Moves the pointer forward by the size of that type

- For types smaller than `int` (`char`, `short`), they’re promoted to `int` due to **default argument promotion**.
  - So: pass `char`, read as `int`.

## What Is **Default Argument Promotion**?

In C, when you pass arguments to a **variadic function** (a function using `...`), the compiler applies _default argument promotions_ to the variable arguments.
Because variadic functions **don’t have type information** for `...`, the compiler promotes certain types to make them predictable and safe.
Because the variadic part (`...`) has **no type information** at compile time, the compiler needs a standard way to handle the arguments to avoid misinterpretation.

### Promotion Rules (For Variadic Arguments)

#### 1. **Integer Promotions**

Types smaller than `int` are promoted to `int`.

#### 2. **Floating Point Promotions**

- `float` is promoted to `double`.
  No more rules.

#### What Happens If You Use the Wrong Type?

- Using the wrong type in `va_arg()` will cause **undefined behavior**, often crashing or producing garbage.

### Kaynakça =>

- https://onepunchcoder.medium.com/variadic-functions-explained-fd3b4ab6fd84
- https://www.geeksforgeeks.org/c/variadic-functions-in-c/
- AI
