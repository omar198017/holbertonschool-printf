#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 */
int print_binary(va_list args, char *buffer, int buff_ind)
{
	unsigned int n = va_arg(args, unsigned int);
	int bits[32];
	int i, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; n > 0; i++)
	{
		bits[i] = n % 2;
		n /= 2;
	}

	for (i = i - 1; i >= 0; i--)
	{
		buffer[buff_ind] = bits[i] + '0';
		write(1, &buffer[buff_ind], 1);
		count++;
	}
	return (count);
}
