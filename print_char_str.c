#include "main.h"

int print_char(va_list args, char *buffer, int buff_ind)
{
	(void)buffer;
	(void)buff_ind;
	char c = va_arg(args, int);
	buffer[buff_ind] = c;
	write(1, &buffer[buff_ind], 1);
	return (1);
}

int print_string(va_list args, char *buffer, int buff_ind)
{
	(void)buffer;
	(void)buff_ind;
	int i;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
		write(1, &str[i], 1);

	return (i);
}

int print_percent(va_list args, char *buffer, int buff_ind)
{
	(void)buffer;
	(void)buff_ind;
	(void)args;
	buffer[buff_ind] = '%';
	write(1, &buffer[buff_ind], 1);
	return (1);
}
