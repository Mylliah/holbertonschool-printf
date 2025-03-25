#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - function that writes a single character to stdout
 * @c: the character to print
 */

void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * print_char - function that prints a single character from va_list arguments
 * @args: variable arguments list containing the character to print
 *
 * Return: 1, number of characters printed
 */

int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
* print_specifier - function that prints a character '%'
* @args: unused arguments list
*
* Return: 1, number of characters printed
*/

int print_specifier(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}


/**
* print_string - prints a string from va_list arguments
* @args: variable arguments list containing the string pointer
*
* Handles NULL pointers by printinf "(null)"
* Return: total number of characters printed
*/

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		_putchar(*str++);
		len++;
	}
	return (len);
}
