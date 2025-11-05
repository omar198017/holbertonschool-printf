#include "main.h"

/**
 * get_handler - gets the corresponding handler for a format specifier
 * @c: format specifier character
 * Return: pointer to the handler function, or NULL if not found
 */
int (*get_handler(char c))(va_list)
{
    format_handler_t handlers[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {'\0', NULL}
    };
    int i;

    for (i = 0; handlers[i].specifier; i++)
    {
        if (handlers[i].specifier == c)
            return (handlers[i].func);
    }
    return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: format string containing characters and specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    int (*func)(va_list);

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                return (-1);

            func = get_handler(format[i]);
            if (func)
                count += func(args);
            else
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
            count += _putchar(format[i]);
        i++;
    }

    va_end(args);
    return (count);
}
