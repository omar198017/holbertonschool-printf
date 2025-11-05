#include "main.h"

/**
 * print_char - prints a character
 * @args: argument list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
    return (_putchar(va_arg(args, int)));
}

/**
 * print_string - prints a string
 * @args: argument list
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
        count += _putchar(*str++);
    return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: argument list (unused)
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
    (void)args;
    return (_putchar('%'));
}

/**
 * print_int - prints an integer
 * @args: argument list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    return (print_number(n));
}
