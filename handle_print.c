#include "main.h"

/**
 * handle_print - Matches format specifier to correct function
 */
int handle_print(const char *format, int *i, va_list args, char *buffer, int *buff_ind)
{
	int j;
	print_handler_t handlers[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
		{'X', print_HEX}, {'p', print_pointer}, {'S', print_custom_S},
		{'r', print_rev}, {'R', print_rot13}, {'\0', NULL}
	};

	for (j = 0; handlers[j].specifier != '\0'; j++)
	{
		if (format[*i] == handlers[j].specifier)
			return (handlers[j].f(args, buffer, *buff_ind));
	}

	_putchar('%');
	_putchar(format[*i]);
	return (2);
}
