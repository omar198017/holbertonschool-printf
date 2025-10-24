#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 * Author: Omar Caguazango
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and specifiers
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;

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

			switch (format[i])
			{
			case 'c':
				count += _putchar(va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
				break;
			case '%':
				count += _putchar('%');
				break;
			case 'd':
			case 'i':
				count += print_number(va_arg(args, int));
				break;
			default:
				count += _putchar('%');
				count += _putchar(format[i]);
				break;
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}

	va_end(args);
	return (count);
}
