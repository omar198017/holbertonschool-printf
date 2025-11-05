#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Author: Omar Caguazango
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
			buffer[buff_ind++] = format[i];
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			if (!format[i])
				return (-1);
			printed += handle_print(format, &i, args, buffer, &buff_ind);
		}
		if (buff_ind == BUFF_SIZE)
			print_buffer(buffer, &buff_ind);
	}
	print_buffer(buffer, &buff_ind);

	va_end(args);
	return (printed);
}
