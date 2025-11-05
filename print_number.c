#include "main.h"

int print_int(va_list args, char *buffer, int buff_ind)
{
	(void)buffer;
	(void)buff_ind;
	int n = va_arg(args, int);
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		count++;
	}
	else
		num = n;

	if (num / 10)
		count += print_int((va_list)&num, buffer, buff_ind);

	_putchar((num % 10) + '0');
	return (count + 1);
}
