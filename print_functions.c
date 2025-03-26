#include "main.h"
#include <stdarg.h>

/**
 * print_char - Affiche un caractère
 * @args: Liste d'arguments
 * Return: 1 (nombre de caractères imprimés)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}

/**
 * print_string - Affiche une chaîne de caractères
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }
    return (count);
}

/**
 * print_int - Affiche un entier (%d, %i)
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[12];
    _itoa(n, buffer, 10);
    return (_strlen(buffer) + write(1, buffer, _strlen(buffer)));
}

/**
 * print_pointer - Affiche un pointeur (%p)
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
 */
int print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    char buffer[20];
    int count;

    if (!ptr)
        return (write(1, "(nil)", 5));

    count = sprintf(buffer, "%p", ptr);
    return (write(1, buffer, count));
}
