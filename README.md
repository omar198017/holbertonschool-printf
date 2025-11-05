
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


# 🖨️ _printf

### Description
`_printf` is a custom implementation of the standard C library function `printf()`.  
It handles formatted output to the standard output stream (`stdout`), supporting both standard and custom conversion specifiers.

This project is part of the **Holberton School Low-Level Programming curriculum**, focusing on variadic functions, function pointers, and formatted output in C.

---

## ✅ Features
Supported conversion specifiers:

| Specifier | Description |
|------------|--------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%%` | Prints a literal percent sign |
| `%d`, `%i` | Prints a signed decimal integer |
| `%b` | Prints an unsigned integer in binary |
| `%u`, `%o`, `%x`, `%X` | Prints unsigned integers (decimal, octal, lowercase hex, uppercase hex) |
| `%p` | Prints a pointer address |
| `%S` | Prints a string and displays non-printable characters as `\xXX` (hex) |
| `%r` | Prints a string in reverse |
| `%R` | Prints a string encoded in ROT13 |

---

### Return Value
The function returns the total number of characters printed (excluding the null byte).  
If an error occurs, it returns `-1`.

---

### Example Usage
```c
#include "main.h"

int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Holberton");
    _printf("Binary: %b\n", 98);
    _printf("Unsigned: %u\n", 1024);
    _printf("Pointer: %p\n", (void *)0x7ffe637541f0);
    _printf("Reverse: %r\n", "Hello");
    _printf("ROT13: %R\n", "Holberton");
    return (0);
}

---

### Expected Output:
Character: A
String: Holberton
Binary: 1100010
Unsigned: 1024
Pointer: 0x7ffe637541f0
Reverse: olleH
ROT13: Ubyoregba

---

### Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf

---

### Project Structure

holberton_printf/
├── main.h
├── _putchar.c
├── _printf.c
├── buffer.c
├── print_char_str.c
├── print_number.c
├── print_binary.c
├── print_unsigned.c
├── print_pointer.c
├── print_custom.c
├── man_3_printf
└── README.md


---

### Requirements

- Code must follow Betty style
- No global variables
- Maximum 5 functions per file
- Only the following functions are allowed:
    - write
    - malloc
    - free
    - va_start
    - va_end
    - va_copy
    - va_arg

Author

Written by Omar Caguazango
Holberton School — Printf Project

man_3_printf
.TH _PRINTF 3 "October 2025" "Holberton School" "C Library Functions"
.SH NAME
_printf \- custom implementation of the printf function
.SH SYNOPSIS
.B #include "main.h"
.br
.BI "int _printf(const char *format, ...);"
.SH DESCRIPTION
The _printf() function produces output according to a format string.
The format string may contain ordinary characters that are copied
to the output stream, and conversion specifiers introduced by the '%'
character.

The implementation supports most common specifiers and flags found
in the standard printf function, as well as several custom ones.

.SH SUPPORTED CONVERSION SPECIFIERS
The following conversion specifiers are handled:

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

.TP
%u
Prints an unsigned decimal integer.

.TP
%o
Prints an unsigned integer in octal (base 8) format.

.TP
%x
Prints an unsigned integer in lowercase hexadecimal (base 16).

.TP
%X
Prints an unsigned integer in uppercase hexadecimal (base 16).

.TP
%b
(From Task 3) Prints an unsigned integer argument in binary (base 2).

.TP
%p
(From Task 6) Prints a pointer address in hexadecimal format.

.TP
%S
(From Task 7) Prints a string. Non-printable characters (ASCII < 32 or ≥ 127)
are printed as \x followed by their two-digit uppercase hexadecimal code.

.TP
%r
(From Task 14) Prints a string in reverse order.

.TP
%R
(From Task 15) Prints a string encoded in ROT13 substitution cipher.

.SH FLAGS
The following flags are handled for numeric conversions (d, i, u, o, x, X):

.TP
+
Prefix positive numbers with a plus sign.

.TP
(space)
Prefix positive numbers with a space if no sign is printed.

.TP
#
Use an alternate form:
.br
- For %o, prefix with '0' if nonzero.
.br
- For %x, prefix with '0x'.
.br
- For %X, prefix with '0X'.

.TP
0
Pads numbers with zeros instead of spaces.

.TP
-
Left-aligns the output within the given field width.

.SH LENGTH MODIFIERS
The following length modifiers are supported (Task 9):

.TP
l
Specifies that the argument is a long or unsigned long integer.

.TP
h
Specifies that the argument is a short or unsigned short integer.

.SH FIELD WIDTH AND PRECISION
(Tasks 10 and 11)

.TP
Field width
Specifies the minimum number of characters to be printed. If the
converted value has fewer characters, it is padded with spaces
(or zeros if the 0 flag is used).

.TP
Precision
Specifies the minimum number of digits to be printed for integers,
or the maximum number of characters to print for strings.

.SH BUFFER OPTIMIZATION
(From Task 5)

A local buffer of 1024 bytes is used to minimize the number of system
calls to write(), improving performance.

.SH VARIADIC FUNCTION IMPLEMENTATION
The _printf function uses variadic arguments via <stdarg.h>. Each
conversion specifier corresponds to a specific handler function
selected dynamically using function pointers.

.SH FUNCTION POINTERS
Function pointers are used to map each format specifier to its
corresponding handler function. This modular design allows easier
maintenance and extension.

.SH RETURN VALUE
Returns the total number of characters printed (excluding the null byte).
In case of an error, returns \-1.

.SH EXAMPLES
.nf
_printf("Character: %c\\n", 'H');
_printf("String: %s\\n", "Holberton");
_printf("Integer: %d\\n", 123);
_printf("Binary: %b\\n", 98);
_printf("Unsigned: %u\\n", 255);
_printf("Octal: %o\\n", 64);
_printf("Hex lowercase: %x\\n", 255);
_printf("Hex uppercase: %X\\n", 255);
_printf("Pointer: %p\\n", &n);
_printf("Custom S: %S\\n", "Best\\nSchool");
_printf("Reversed: %r\\n", "Hello");
_printf("ROT13: %R\\n", "Hello");
.fi

.SH SEE ALSO
printf(3), write(2), va_start(3), va_arg(3), va_end(3)
.SH AUTHOR
Developed by
.B Omar Caguazango
.br
Holberton School printf project group (2025)
