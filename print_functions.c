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
    int length = 0, temp, is_negative = 1;

if (num < 0)
{
    is_negative = -1;
    num = -num;
    _putchar('-');
        length++;
}

    temp = num;
    if (temp == 0)
    {
        _putchar('0');
        return (1);
    }

    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    char number_str[length];
    number_str[length] = '\0';

    while (num > 0)
    {
        number_str[--length] = (num % 10) + '0';
        num /= 10;
    }

    for (int i = 0; number_str[i] != '\0'; i++)

    _putchar(number_str[i]);

    return (length);
}
