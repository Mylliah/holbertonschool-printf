#include "main.h"

/**
 * print_char 
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}

/**
 * print_string 
 */
int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int i;

    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
        _putchar(s[i]);

    return (i);
}

/**
 * print_percent
 */
int print_percent(__attribute__((unused)) va_list args)
{
    return (_putchar('%'));
}

/**
 * print_int 
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[12]; 
    int count;

    _itoa(n, buffer);
    count = _strlen(buffer);
    write(1, buffer, count);

    return (count);
}
