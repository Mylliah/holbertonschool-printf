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
 * Handles NULL pointers by printing "(null)"
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


/**
 * print_int - function that prints an integer from va_list arguments
 * @args: variable arguments list containing the integer to print
 *
 * Return: number of characters printed
 */

int print_int(va_list args)
{
	int num = va_arg(args, int);

	int len = 0;
	unsigned int abs_num;
	unsigned int divisor = 1;

	if (num < 0)
	{
		_putchar('-');
		len++;
		abs_num = (unsigned int)(-num);
	}
	else
	{
		abs_num = (unsigned int)num;
	}

	if (abs_num == 0)
	{
		_putchar('0');
		return (len + 1);
	}

	while (abs_num / divisor > 9)
		divisor *= 10;

	while (divisor > 0)
	{
		_putchar((abs_num / divisor) + '0');
		abs_num %= divisor;
		divisor /= 10;
		len++;
	}

	return (len);
}