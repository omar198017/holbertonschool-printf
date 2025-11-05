#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

/**
 * struct print_handler - Struct for mapping specifiers to functions
 * @specifier: format specifier character
 * Author: Omar Caguazango
 * @f: function pointer to handler
 */

 typedef struct print_handler
{
	char specifier;
	int (*f)(va_list, char *, int);
} print_handler_t;

/* Prototypes */

int _printf(const char *format, ...);

int _putchar(char c);

int handle_print(const char *format, int *i, va_list args, char *buffer, int *buff_ind);

void print_buffer(char *buffer, int *buff_ind);

/* print functions */

int print_char(va_list args, char *buffer, int buff_ind);

int print_string(va_list args, char *buffer, int buff_ind);

int print_percent(va_list args, char *buffer, int buff_ind);

int print_int(va_list args, char *buffer, int buff_ind);

int print_binary(va_list args, char *buffer, int buff_ind);

int print_unsigned(va_list args, char *buffer, int buff_ind);

int print_octal(va_list args, char *buffer, int buff_ind);

int print_hex(va_list args, char *buffer, int buff_ind);

int print_HEX(va_list args, char *buffer, int buff_ind);

int print_pointer(va_list args, char *buffer, int buff_ind);

int print_custom_S(va_list args, char *buffer, int buff_ind);

int print_rev(va_list args, char *buffer, int buff_ind);

int print_rot13(va_list args, char *buffer, int buff_ind);

#endif /* MAIN_H */
