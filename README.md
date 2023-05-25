# ft_printf

Welcome to the `ft_printf` project! This project is part of the curriculum at School 42 and is designed to help you understand and implement the functionality of the C standard library function `printf`.

## Installation

To get started with the `ft_printf` project, follow these steps:

1. Clone the project repository from the School 42 GitLab server.
2. Navigate to the project directory.

## Usage

To use the `ft_printf` function in your own programs, follow these steps:

1. Include the `ft_printf.h` header file in your source code.
2. Link your program with the `libftprintf.a` library.
3. Call the `ft_printf` function with the desired format string and arguments.

Here's an example of how to use `ft_printf`:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Hello, %d!\n", 42);
    return 0;
}
```

In the example above, `ft_printf` is used to print a string and a formatted floating-point number to the console.

## Documentation

The `ft_printf` function supports a wide range of format specifiers and options. Here are some commonly used format specifiers:

- `%d` or `%i`: Signed decimal integer.
- `%u`: Unsigned decimal integer.
- `%s`: String.
- `%c`: Character.
- `%x` or `%X`: Hexadecimal number.
- `%o`: Octal number.
- `%p`: Pointer address.

For detailed information about the available format specifiers and their options, refer to the documentation or the project source code.

## Credits

This project was completed by Thibault GIRAUDON (tgiraudo) as part of the curriculum at École 42.
