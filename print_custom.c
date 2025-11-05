#include "main.h"
#include <ctype.h>

/* %S - Non-printable chars in \x format */
int print_custom_S(va_list args, char *buffer, int buff_ind)
{
	(void)buffer;
	(void)buff_ind;
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += write(1, "\\x", 2);
			if (str[i] < 16)
				count += _putchar('0');
			count += _printf("%X", str[i]);
		}
		else
			count += _putchar(str[i]);
	}

	return (count);
}

/* %r - prints reversed string */
int print_rev(va_list args, char *buffer, int buff_ind)
{
	(void)buffer;
	(void)buff_ind;
	char *str = va_arg(args, char *);
	int len = 0, count = 0;

	if (!str)
		str = "(null)";

	while (str[len])
		len++;

	while (len--)
		count += _putchar(str[len]);

	return (count);
}

/* %R - prints rot13 string */
int print_rot13(va_list args, char *buffer, int buff_ind)
{
	(void)buffer;
	(void)buff_ind;
	char *str = va_arg(args, char *);
	int i, j, count = 0;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[]   = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; alpha[j]; j++)
		{
			if (str[i] == alpha[j])
			{
				count += _putchar(rot[j]);
				break;
			}
		}
		if (!alpha[j])
			count += _putchar(str[i]);
	}
	return (count);
}
