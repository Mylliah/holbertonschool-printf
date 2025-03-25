#include "main.h"
#include <stdarg.h>

/**
 * handle_specifier - handles format specifiers after '%' character
 * @format: format string to be handle
 * @args: variable arguments list
 * @index: pointer to current position index in format string
 *
 * Calls the corresponding function
 * Return: number of characters printed for the specifier found
 */

int handle_specifier(const char *format, va_list args, int *index)
{
	int count = 0;
	int type_found = 0;

	print_format types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_specifier},
		{'\0', NULL}
	};

	for (int type_index = 0 ; types[type_index].type ; type_index++)
	{
		if (format[*index] == types[type_index].type)
		{
			count += types[type_index].f(args);
			type_found = 1;
			break;
		}
	}

	if (!type_found)
	{
		_putchar('%');
		_putchar(format[*index]);
		count += 2;
	}
	return (count);
}



/**
 * _printf - implementation of printf
 * @format: format string containing text and specifiers
 *
 * Return: -1 for NULL, empty format strg OR total number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	int index = 0;
	int count = 0;

	va_start(args, format);

	if (!format || format[0] == '\0')
		return (-1);

	while (format && format[index])
	{
		if (format[index] == '%')
		{
			index++;
			count += handle_specifier(format, args, &index);
		}
		else
		{
			_putchar(format[index]);
			count++;
		}
		index++;
	}

	va_end(args);
	return (count);
}
