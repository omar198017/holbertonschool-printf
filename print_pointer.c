#include "main.h"

/**
 * print_pointer - prints a pointer address
 */
int print_pointer(va_list args, char *buffer, int buff_ind)
{
	unsigned long ptr = (unsigned long)va_arg(args, void *);
	char hex[20];
	int i = 0, count = 0;
	char *digits = "0123456789abcdef";

	if (!ptr)
		return (write(1, "(nil)", 5));

	write(1, "0x", 2);
	count += 2;

	while (ptr)
	{
		hex[i++] = digits[ptr % 16];
		ptr /= 16;
	}

	while (i--)
		count += _putchar(hex[i]);

	return (count);
}
