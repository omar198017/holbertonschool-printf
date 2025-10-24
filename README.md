
# [C#28] SEIP - Part 1.-  C - printf

Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

![Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/a/af/GNU_Compiler_Collection_logo.svg/508px-GNU_Compiler_Collection_logo.svg.png)

## Authors

- [@omar198017](https://www.github.com/omar198017)

      |\ _,,,---,,_
  
ZZZzz /,`.-'`' -. ;-;;,_

     |,4- ) )-,_. ,\ ( `'-'
     
    '---''(_/--' `-'\_) Chino


    

![Logo](https://www.muylinux.com/wp-content/uploads/2018/11/bash.png)


# _printf

### Description
The `_printf` function is a custom implementation of the standard C library `printf` function.  
It produces formatted output to the standard output stream (`stdout`) using a format string that specifies how subsequent arguments are converted for output.

This project is part of the **Holberton School Low-Level Programming curriculum** and aims to strengthen understanding of variadic functions, function pointers, and output formatting in C.

---

### Prototype
```c
int _printf(const char *format, ...);

| Specifier | Description                            |
| --------- | -------------------------------------- |
| `%c`      | Prints a single character              |
| `%s`      | Prints a string of characters          |
| `%%`      | Prints a literal percent sign          |
| `%d`      | Prints a signed decimal integer        |
| `%i`      | Prints a signed integer (same as `%d`) |

### Return Value

_printf returns the total number of characters printed (excluding the null byte used to end output strings).
If an error occurs, it returns -1.

Usage Example
cat example.c

#include "main.h"

int main(void)
{
    int len;

    len = _printf("Character: [%c]\n", 'H');
    _printf("String: [%s]\n", "Hello, world!");
    _printf("Percent: [%%]\n");
    _printf("Integer: [%d]\n", 12345);
    _printf("Length returned: [%d]\n", len);

    return (0);
}

Output:

Character: [H]
String: [Hello, world!]
Percent: [%]
Integer: [12345]
Length returned: [15]

Compilation

All files are compiled on Ubuntu 20.04 LTS using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c


Project Structure

holbertonschool-printf/
├── _printf.c
├── _putchar.c
├── main.h
├── man_3_printf
└── README.md

Requirements

* Code must follow Betty style
* No global variables
* No more than 5 functions per file
* Use only allowed functions:
    - write
    - malloc
    - free
    - va_start
    - va_end
    - va_copy
    - va_arg

Acknowledgements

This project was developed as part of the Holberton School C programming track.
Inspired by the original printf(3) function from the C Standard Library.


## File: `man_3_printf`

```man
.TH _PRINTF 3 "October 2025" "Holberton School" "C - Printf Library Functions"
.SH NAME
_printf \- custom implementation of the printf function
.SH SYNOPSIS
.B #include "main.h"
.br
.BI "int _printf(const char *format, ...);"
.SH DESCRIPTION
The
.B _printf()
function produces output according to a format string.
The format string is composed of zero or more directives.
Ordinary characters in the string are copied to the output stream.
Conversion specifiers, introduced by the percent character (%),
determine how the following arguments are formatted and printed.

The supported conversion specifiers are:

.TP
%c
Prints a single character.

.TP
%s
Prints a string of characters.

.TP
%%
Prints a literal percent sign.

.TP
%d, %i
Prints a signed decimal integer.

.SH RETURN VALUE
Returns the total number of characters printed (excluding the null byte).
If an error occurs, the function returns \-1.

.SH EXAMPLES
.nf
_printf("Character: %c\\n", 'H');
_printf("String: %s\\n", "Holberton");
_printf("Percent: %%\\n");
_printf("Integer: %d\\n", 12345);
.fi

.SH COMPILATION
.nf
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
.fi

.SH SEE ALSO
printf(3)

.SH AUTHOR
Written by Omar Caguazango for Holberton School.
