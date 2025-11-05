#include "main.h"

int print_unsigned(va_list args, char *buffer, int buff_ind)
{
	unsigned int n = va_arg(args, unsigned int);
	char digits[20];
	int i = 0, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n)
	{
		digits[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i--)
		count += _putchar(digits[i]);

	return (count);
}

/* octal */
int print_octal(va_list args, char *buffer, int buff_ind)
{
	unsigned int n = va_arg(args, unsigned int);
	char digits[20];
	int i = 0, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n)
	{
		digits[i++] = (n % 8) + '0';
		n /= 8;
	}

	while (i--)
		count += _putchar(digits[i]);

	return (count);
}

/* hexadecimal lower */
int print_hex(va_list args, char *buffer, int buff_ind)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex[20];
	int i = 0, count = 0;
	char *digits = "0123456789abcdef";

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n)
	{
		hex[i++] = digits[n % 16];
		n /= 16;
	}

	while (i--)
		count += _putchar(hex[i]);

	return (count);
}

/* hexadecimal upper */
int print_HEX(va_list args, char *buffer, int buff_ind)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex[20];
	int i = 0, count = 0;
	char *digits = "0123456789ABCDEF";

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n)
	{
		hex[i++] = digits[n % 16];
		n /= 16;
	}

	while (i--)
		count += _putchar(hex[i]);

	return (count);
}
