#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_number(int n);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

/**
 * struct format_handler - Struct for mapping format specifiers to functions
 * @specifier: The format character (e.g. 'c', 's', 'd')
 * @func: The function that handles that specifier
 */
typedef struct format_handler
{
    char specifier;
    int (*func)(va_list);
} format_handler_t;

#endif /* MAIN_H */
