#include "main.h"

/**
 * struct format_info - stores parsed format data
 * @flags: flags found (+, -, #, 0, space)
 * @width: minimum width
 * @precision: number of digits or chars precision
 * @length: 'l' or 'h'
 */
typedef struct format_info
{
	int flags[5];  /* ['+', '-', '#', '0', ' '] order */
	int width;
	int precision;
	char length;
} format_info_t;

/**
 * init_format_info - initializes structure to defaults
 */
void init_format_info(format_info_t *info)
{
	int i;

	for (i = 0; i < 5; i++)
		info->flags[i] = 0;
	info->width = 0;
	info->precision = -1;
	info->length = 0;
}

/**
 * parse_flags - parses flags from format string
 */
int parse_flags(const char *format, int *i, format_info_t *info)
{
	int done = 0;

	while (!done)
	{
		switch (format[*i])
		{
		case '+': info->flags[0] = 1; break;
		case '-': info->flags[1] = 1; break;
		case '#': info->flags[2] = 1; break;
		case '0': info->flags[3] = 1; break;
		case ' ': info->flags[4] = 1; break;
		default: done = 1; continue;
		}
		(*i)++;
	}
	return (*i);
}

/**
 * parse_width_precision - parses width and precision
 */
int parse_width_precision(const char *format, int *i, format_info_t *info, va_list args)
{
	if (format[*i] == '*')
	{
		info->width = va_arg(args, int);
		(*i)++;
	}
	else
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			info->width = info->width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	if (format[*i] == '.')
	{
		(*i)++;
		info->precision = 0;
		if (format[*i] == '*')
		{
			info->precision = va_arg(args, int);
			(*i)++;
		}
		else
		{
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				info->precision = info->precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}
	return (*i);
}

/**
 * parse_length - parses l or h length modifiers
 */
int parse_length(const char *format, int *i, format_info_t *info)
{
	if (format[*i] == 'l' || format[*i] == 'h')
		info->length = format[(*i)++];
	return (*i);
}
